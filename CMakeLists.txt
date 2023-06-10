cmake_minimum_required(VERSION 3.22.1) 

project(LEFT4DEAD)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
set(CLIENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Client)
set(SERVER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Server)
file(GLOB CLIENT_SOURCES ${CLIENT_SOURCE_DIR}/*.cpp)
file(GLOB CLIENT_HEADERS ${CLIENT_SOURCE_DIR}/*.h)

add_executable(client ${CLIENT_SOURCES} ${CLIENT_HEADERS})
add_subdirectory(SDL2pp)
target_link_libraries(client SDL2pp)
file(GLOB SERVER_SOURCES ${SERVER_SOURCE_DIR}/*.cpp)
file(GLOB SERVER_HEADERS ${SERVER_SOURCE_DIR}/*.h)
add_executable(server ${SERVER_SOURCES} ${SERVER_HEADERS})
target_link_libraries(server SDL2pp)
