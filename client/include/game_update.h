#ifndef GAME_UPDATE_H
#define GAME_UPDATE_H

#include <cstdint>
#include "state_types.h"

class GameUpdate {
 private:
    CHARACTER typeCharacter;
    uint8_t owner;
    ACTION action;
    int32_t posX;
    int32_t posY;
    uint8_t direction;

 public:
    GameUpdate();
    GameUpdate(CHARACTER typeCharacter, uint8_t owner, ACTION action, int32_t posX, int32_t posY, uint8_t direction);
    //getters and setters
    CHARACTER getTypeCharacter() const;
    uint8_t getOwner() const;
    ACTION getAction() const;
    int32_t getPosX() const;
    int32_t getPosY() const;
    uint8_t getDirection() const;
    void setTypeCharacter(CHARACTER typeCharacter);
    void setOwner(uint8_t owner);
    void setAction(ACTION action);
    void setPosX(int32_t posX);
    void setPosY(int32_t posY);
    void setDirection(uint8_t direction);
    ~GameUpdate();
};

#endif // GAME_UPDATE_H
