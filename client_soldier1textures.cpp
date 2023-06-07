#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_soldier1textures.h"
#include <vector>

Soldier1_Textures::Soldier1_Textures(SDL2pp::Renderer* renderer): 
    attack(*renderer,"../resources/Soldier_1/Attack.png"),
    dead(*renderer,"../resources/Soldier_1/Dead.png"),
    grenade(*renderer,"../resources/Soldier_1/Grenade.png"),
    hurt(*renderer,"../resources/Soldier_1/Hurt.png"),
    idle(*renderer,"../resources/Soldier_1/Idle.png"),
    recharge(*renderer,"../resources/Soldier_1/Recharge.png"),
    run(*renderer,"../resources/Soldier_1/Run.png"),
    shot_1(*renderer,"../resources/Soldier_1/Shot_1.png"),
    shot_2(*renderer,"../resources/Soldier_1/Shot_2.png"),
    walk(*renderer,"../resources/Soldier_1/Walk.png")
{

}
std::vector<SDL2pp::Texture*> Soldier1_Textures::all_textures(){
    std::vector<SDL2pp::Texture*> all_textures;
    all_textures.push_back(&attack);
    all_textures.push_back(&dead);
    all_textures.push_back(&grenade);
    all_textures.push_back(&hurt);
    all_textures.push_back(&idle);
    all_textures.push_back(&recharge);
    all_textures.push_back(&run);
    all_textures.push_back(&shot_1);
    all_textures.push_back(&shot_2);
    all_textures.push_back(&walk);
    return all_textures;
}