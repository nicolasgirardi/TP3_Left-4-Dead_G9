#include "../include/GameUpdate.h"

GameUpdate::GameUpdate() {
    this->typeCharacter = CHARACTER::NONE_CHARACTER;
    this->owner = 0;
    this->action = ACTION::NONE_ACTION;
    this->posX = 0;
    this->posY = 0;
    this->direction = 0;
}

GameUpdate::GameUpdate(CHARACTER typeCharacter, uint8_t owner, ACTION action, int32_t posX,
                       int32_t posY, uint8_t direction) :
                       typeCharacter(typeCharacter), owner(owner),
                       action(action), posX(posX), posY(posY),
                       direction(direction) {}

CHARACTER GameUpdate::getTypeCharacter() const {
    return this->typeCharacter;
}

uint8_t GameUpdate::getOwner() const {
    return this->owner;
}

ACTION GameUpdate::getAction() const {
    return this->action;
}

int32_t GameUpdate::getPosX() const {
    return this->posX;
}

int32_t GameUpdate::getPosY() const {
    return this->posY;
}

uint8_t GameUpdate::getDirection() const {
    return this->direction;
}

void GameUpdate::setTypeCharacter(const CHARACTER typeCharacter) {
    this->typeCharacter = typeCharacter;
}

void GameUpdate::setOwner(const uint8_t owner) {
    this->owner = owner;
}

void GameUpdate::setAction(const ACTION action) {
    this->action = action;
}

void GameUpdate::setPosX(const int32_t posX) {
    this->posX = posX;
}

void GameUpdate::setPosY(const int32_t posY) {
    this->posY = posY;
}

void GameUpdate::setDirection(const uint8_t direction) {
    this->direction = direction;
}

GameUpdate::~GameUpdate() {}

