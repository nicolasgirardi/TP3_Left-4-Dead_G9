#include <iostream>
#include "server_client.h"


Client::Client(Socket& socket,Allgames* games){
    status = false;
    receiver = new Reciever(socket,games,&status);
}
void Client::start(){
    receiver->start();
}
void Client::finish(){
    if  (!status){
        status = true;
        receiver->finish();
    }
}
void Client::join(){
    this->finish();
    receiver->join();
}
Client::~Client(){
    delete receiver;
}
