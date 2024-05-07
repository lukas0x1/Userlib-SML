cmake_minimum_required(VERSION 3.19.0)

set(CIPHER_URL https://github.com/lukas0x1/Userlib-SML/releases/latest/download/libciphered.so)
set(CIPHER_PATH ${CMAKE_BINARY_DIR}/libciphered.so)
file(DOWNLOAD ${CIPHER_URL} ${CIPHER_PATH} STATUS LIBCIPHER_DOWNLOAD_STATUS)


project("userlib")


#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_C_VISIBILITY_PRESET hidden)
        set(CMAKE_CXX_VISIBILITY_PRESET hidden)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden -O3")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -O3")
endif()


file(READ ${CMAKE_HOME_DIRECTORY}/config.json MY_JSON_STRING) #reads soname from config
string(JSON CUR_NAME GET ${MY_JSON_STRING} name)
string(LENGTH ${CUR_NAME} CUR_NAME_LEN)
string(SUBSTRING ${CUR_NAME} 3 ${CUR_NAME_LEN} CUR_NAME) #ugly but there's no lazy regex support
string(REPLACE ".so" "" CUR_NAME ${CUR_NAME})

add_library( # Sets the name of the library.
        ${CUR_NAME}
        SHARED
        main.cpp
)

target_include_directories(
        ${CUR_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include
)

find_library(
        log-lib
        log
)

target_link_libraries(
        ${CUR_NAME}
        "${CIPHER_PATH}"
        ${log-lib}
)

add_custom_command(
        TARGET ${CUR_NAME}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS --add-section .config=${CMAKE_HOME_DIRECTORY}/config.json --set-section-flags .config=readonly,contents,data $<TARGET_FILE:${CUR_NAME}>
)

add_custom_command(
        TARGET ${CUR_NAME}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS --add-section .icon=${CMAKE_HOME_DIRECTORY}/icon.bmp --set-section-flags .icon=readonly,contents,data $<TARGET_FILE:${CUR_NAME}>
)