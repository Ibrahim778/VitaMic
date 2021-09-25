#include<vitasdk.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 256
#define GRAIN 256
#define FREQ 16000

int main()
{
    short *buff = (short *)malloc(sizeof(short) * SIZE);
    sceClibMemset(buff, 0, sizeof(buff)); //wth is memset?!

    int port = sceAudioInOpenPort(SCE_AUDIO_IN_PORT_TYPE_VOICE, GRAIN, FREQ, SCE_AUDIO_IN_PARAM_FORMAT_S16_MONO);
    int outPort = sceAudioOutOpenPort(SCE_AUDIO_OUT_PORT_TYPE_BGM, SIZE, FREQ, SCE_AUDIO_OUT_PARAM_FORMAT_S16_MONO);

    SceCtrlData dat;
    do
    {
        sceCtrlPeekBufferPositive(0, &dat, 1);

        sceAudioInInput(port, buff);
        sceAudioOutOutput(outPort, buff);        

        sceKernelDelayThread(10000);
    } while (!(dat.buttons && SCE_CTRL_START));

    free(buff);
    sceAudioInReleasePort(port);
    sceAudioOutReleasePort(outPort);
    
    return sceKernelExitDeleteThread(0);
}