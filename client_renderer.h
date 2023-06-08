#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H
#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"
#include "client_war1.h"
#include "client_character.h"
#include "client_soldier1.h"
#include "client_center.h"
#include "client_thread.h"
#include "client_queue.h"
//#include "client_Message.h"
#include <memory>

class MyRenderer: public Thread {
    private:
    int width;
    int height;
    int my_map;
    int my_id;
    //Queue<Message>* my_queue;

    public:
    MyRenderer(int width, int height,int map,int ID/*,Queue<Message>* queue*/);

    void run();
    
    private:
    void get_map_paths(std::vector<std::string>& textures);
    void load_map();
};
#endif
