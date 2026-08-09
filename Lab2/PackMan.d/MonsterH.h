#ifndef H_MONSTER
#define H_MONSTER

#include "BoardObjectH.h"

/**
 * @brief Possible states of a Monster object.
 */
enum MonsterState { MONSTER_ACTIVE, MONSTER_CAPTURED };

/**
 * @brief Monster is an enemy object on the board.
 *
 * In this lab, Monster is implemented as a simple BoardObject subclass.
 * Its touch() method changes its displayed colour to demonstrate that it
 * can behave as an independent game object.
 */
class Monster : public BoardObject
{
private:
    MonsterState status;
    ObjectColours color1;
    ObjectColours color2;

public:
    /**
     * @brief Constructs a Monster object at the given board position.
     * @param start_x Initial row position.
     * @param start_y Initial column position.
     */
    Monster(int start_x, int start_y);

    /**
     * @brief Updates the monster colour according to its state.
     */
    virtual void touch();
};

#endif