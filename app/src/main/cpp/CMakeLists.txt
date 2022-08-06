cmake_minimum_required(VERSION 3.19.0)
set(CIPHER_URL https://github.com/ehter0x1/SML-filehost/releases/latest/download/libciphered.so)
set(CIPHER_PATH ${CMAKE_BINARY_DIR}/libciphered.so)
file(DOWNLOAD ${CIPHER_URL} ${CIPHER_PATH} STATUS LIBCIPHER_DOWNLOAD_STATUS)

project("userlib")

file(READ ${CMAKE_HOME_DIRECTORY}/config.json MY_JSON_STRING) #reads soname from config
string(JSON CUR_NAME GET ${MY_JSON_STRING} name)
string(LENGTH ${CUR_NAME} CUR_NAME_LEN)
string(SUBSTRING ${CUR_NAME} 3 ${CUR_NAME_LEN} CUR_NAME) #ugly but there's no lazy regex support
string(REPLACE ".so" "" CUR_NAME ${CUR_NAME})

add_library( # Sets the name of the library.
        ${CUR_NAME}
        SHARED
        main.cpp
        includes/cipher/cipher.cpp
        )

find_library(
        log-lib
        log)

target_link_libraries(
        ${CUR_NAME}
        "${CIPHER_PATH}"
        ${log-lib})

add_custom_command(
        TARGET ${CUR_NAME}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS --add-section .config=${CMAKE_HOME_DIRECTORY}/config.json --set-section-flags .config=readonly,contents,data $<TARGET_FILE:${CUR_NAME}>
)
