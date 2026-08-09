#ifndef H_BOMB
#define H_BOMB

#include "BoardObjectH.h"

/**
 * @brief Possible states of a Bomb object.
 */
enum BombState { BOMB_ACTIVE, BOMB_USED };

/**
 * @brief Bomb is a special board object.
 *
 * In this lab, Bomb is implemented as a simple BoardObject subclass.
 * Its touch() method changes colour to demonstrate independent behaviour.
 */
class Bomb : public BoardObject
{
private:
    BombState status;
    ObjectColours color1;
    ObjectColours color2;

public:
    /**
     * @brief Constructs a Bomb object at the given board position.
     * @param start_x Initial row position.
     * @param start_y Initial column position.
     */
    Bomb(int start_x, int start_y);

    /**
     * @brief Updates the bomb colour according to its state.
     */
    virtual void touch();
};

#endif