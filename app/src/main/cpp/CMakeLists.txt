cmake_minimum_required(VERSION 3.18.1)


project("userlib")

set(LIB_DIR ${CMAKE_HOME_DIRECTORY}/../../../libs)


add_library( # Sets the name of the library.
        userlib
        SHARED
        main.cpp
        includes/cipher/cipher.cpp
        )



find_library(
        log-lib
        log)



target_link_libraries(
        userlib
        "${LIB_DIR}/libciphered.so"
        ${log-lib})

add_custom_command(
        TARGET userlib
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS --add-section .config=${CMAKE_HOME_DIRECTORY}/config.json --set-section-flags .config=readonly,contents,data $<TARGET_FILE:userlib>
)
