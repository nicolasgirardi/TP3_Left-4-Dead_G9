cmake_minimum_required(VERSION 3.22.1) 

project(LEFT4DEAD)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(SDL2pp)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(LEFT4DEAD SDL2pp)

