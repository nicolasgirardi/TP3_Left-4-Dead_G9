cmake_minimum_required(VERSION 3.22.1) 

project(LEFT4DEAD)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
file(GLOB_RECURSE SOURCES 
    client_scenario.cpp
    client_war1.cpp
    main.cpp
    client_character.cpp
    client_soldier1.cpp
    client_animation.cpp
    client_center.cpp
    client_Textureholder.cpp
)
file(GLOB_RECURSE HEADERS 
    client_scenario.h
    client_war1.h
    client_character.h
    client_soldier1.h
    client_animation.h
    client_center.h
    client_Textureholder.h
    client_constants.h
)
add_subdirectory(SDL2pp)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(LEFT4DEAD SDL2pp)

