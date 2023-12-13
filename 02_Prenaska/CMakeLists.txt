cmake_minimum_required(VERSION 3.5)

project(02_Prenaska LANGUAGES C)

add_executable(02_Prenaska Retazec_01.c
    Retazec_02.c
    Smerniky_01.c
    Smerniky_02.c
    Zadanie_01.c
    Printf_01.c
    Celzium.c
    charr.c
    Zadanie_02.c
    Zadanie_03.c
    isAlpha.c
    Zadanie_04.c
    Zadanie_05.c
    Zadanie_06.c
    Zadanie_07.c
    Zadanie_08.c
)

include(GNUInstallDirs)
install(TARGETS 02_Prenaska
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
