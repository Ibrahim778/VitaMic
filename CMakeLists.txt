cmake_minimum_required(VERSION 2.8)
project(VitaMic)
include($ENV{VITASDK}/common.cmake)

add_executable(${PROJECT_NAME}
    src/main.c
)

target_link_libraries(${PROJECT_NAME}
    SceLibKernel_stub
    SceAudio_stub
    SceCtrl_stub
    SceAudioIn_stub
)

set(VITA_APP_NAME "Vita Mic")
set(VITA_TITLEID  "VMIC00001")
set(VITA_VERSION  "01.00")

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
)