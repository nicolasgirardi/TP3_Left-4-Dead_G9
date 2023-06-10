#include "common_socket.h"
#include "server_thread.h"
#include "server_queue.h"
#include "server_message.h"
#include "server_sender.h"
#include "server_protocol.h"

Sender::Sender(Socket* socket,Queue<Message>* queue){
    skt = socket;
    my_queue = queue;
    close = false;
}

void Sender::run(){
    Protocol protocol;
    Message message;
    try {
        while (!close){
            message =  my_queue->pop();
            protocol.send(skt,&close,message);
        }
    }
    catch (std::exception &e){}
}
