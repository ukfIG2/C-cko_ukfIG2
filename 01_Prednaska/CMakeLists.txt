cmake_minimum_required(VERSION 3.5)

project(01_Prednaska LANGUAGES C)

add_executable(01_Prednaska main.c
    01.c
    02.c
    Zadanie_01.c
    Zadanie_02.c
    Zadanie_03.c
    Zadanie_04.c
    Zadanie_05.c
    smerniky.c
    Test.c



)

include(GNUInstallDirs)
install(TARGETS 01_Prednaska
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
