#ifndef LEFT4DEAD_USER_ACTION_H
#define LEFT4DEAD_USER_ACTION_H

#include <cstdint>

class UserAction {
private:
    uint8_t idAction;
    int32_t param1;
    int32_t param2;
public:
    UserAction(uint8_t idAction, int32_t param1, int32_t param2) : idAction(idAction), param1(param1), param2(param2) {}

    UserAction() {
    }

    uint8_t getIdAction() const {
        return idAction;
    }

    int32_t getParam1() const {
        return param1;
    }

    int32_t getParam2() const {
        return param2;
    }
};
#endif // LEFT4DEAD_USER_ACTION_H
