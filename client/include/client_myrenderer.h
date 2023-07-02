#ifndef CLIENT_MYRENDERER_H
#define CLIENT_MYRENDERER_H
#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"
#include "client_war1.h"
#include "../../common_libs/include/common_character.h"
#include "client_soldier1.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_message.h"
#include "client_textureholder.h"
#include "../../common_libs/include/common_myenum.h"
#include <memory>



class MyRenderer: public Thread {
    private:
    int width;
    int height;
    Type_of_map my_map;
    int my_id;
    uint32_t frame;
    Queue<Message>* my_queue;
    std::vector<Character*> all_characters;
    std::vector<Texture_holder*> all_textures;
    std::vector<std::string> soldier_type_1;
	std::vector<std::string> soldier_type_2;
	std::vector<std::string> soldier_type_3;
	std::vector<std::string> enemy_jumper;
	std::vector<std::string> enemy_spear;
	std::vector<std::string> enemy_venom;
	std::vector<std::string> enemy_witch;
	std::vector<std::string> enemy_zombie;
    std::vector<std::string> explotion_effect;
    std::vector<std::string> smoke_effect;

    public:
    MyRenderer(int width, int height,Type_of_map map,int ID,Queue<Message>* queue);

    void run() override;

    ~MyRenderer();
    
    private:
    void get_map_paths(std::vector<std::string>& textures);
    void load_map();
    void update_characters(Message& message);
    void add_character(Message& message);
    void modify_character(Message& message);
    void remove_character(Message& message);
    void calculate_center(Center& center);
    void texture_paths();
    void copy_characters(int& center,SDL2pp::Renderer* renderer);

};
#endif
