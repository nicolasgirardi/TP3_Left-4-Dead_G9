cmake_minimum_required(VERSION 3.22.1) 

project(LEFT4DEAD)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
file(GLOB_RECURSE SOURCES 
    client_scenario.cpp
    client_war1.cpp
    client_war2.cpp
    client_war3.cpp
    client_war4.cpp
    main.cpp
    client_character.cpp
    client_soldier1.cpp
    client_animation.cpp
    client_loopanimation.cpp
    client_singleanimation.cpp
    client_noloopanimation.cpp
    client_center.cpp
    client_textureholder.cpp
    client_myrenderer.cpp
    client_soldier2.cpp
    client_soldier3.cpp
    client_jumper.cpp
    client_spear.cpp
    client_venom.cpp
    client_witch.cpp
    client_zombie.cpp
    client_explotion.cpp
    client_smoke.cpp
    client_message.cpp
)
file(GLOB_RECURSE HEADERS 
    client_scenario.h
    client_war1.h
    client_war2.h
    client_war3.h
    client_war4.h
    client_character.h
    client_soldier1.h
    client_animation.h
    client_loopanimation.h
    client_singleanimation.h
    client_noloopanimation.h
    client_center.h
    client_Textureholder.h
    client_constants.h
    client_myrenderer.h
    common_thread.h
    common_queue.h
    client_soldier2.h
    client_soldier3.h
    client_jumper.h
    client_spear.h
    client_venom.h
    client_witch.h
    client_zombie.h
    client_explotion.h
    client_smoke.h
    client_message.h
    client_myenum.h
)
add_subdirectory(SDL2pp)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(LEFT4DEAD SDL2pp)

