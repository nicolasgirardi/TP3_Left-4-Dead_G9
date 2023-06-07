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
#include "client_constants.h"
#include <vector>

using namespace paths;

Soldier1_Textures::Soldier1_Textures(SDL2pp::Renderer* renderer): 
    attack(*renderer,Soldier_1_Attack),
    dead(*renderer,Soldier_1_Dead),
    grenade(*renderer,Soldier_1_Grenade),
    hurt(*renderer,Soldier_1_Hurt),
    idle(*renderer,Soldier_1_Idle),
    recharge(*renderer,Soldier_1_Recharge),
    run(*renderer,Soldier_1_Run),
    shot_1(*renderer,Soldier_1_Shot_1),
    shot_2(*renderer,Soldier_1_Shot_2),
    walk(*renderer,Soldier_1_Walk)
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