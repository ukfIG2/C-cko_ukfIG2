cmake_minimum_required(VERSION 3.5)

project(03_Prednaska LANGUAGES C)

add_executable(03_Prednaska main.c)

include(GNUInstallDirs)
install(TARGETS 03_Prednaska
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
