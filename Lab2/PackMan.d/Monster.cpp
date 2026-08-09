/**
 * @file Monster.cpp
 * @brief Implementation of the Monster class.
 */

#include "BoardObjectH.h"
#include "MonsterH.h"

Monster::Monster(int start_x, int start_y) : BoardObject(start_x, start_y)
{
    status = MONSTER_ACTIVE;
    color1 = RED;
    color2 = BLUE;
    myClass = A_MONSTER;
}

void Monster::touch()
{
    switch (status)
    {
        case MONSTER_ACTIVE:
            if (color1 == get_Color())
                set_color(color2);
            else
                set_color(color1);
            break;

        case MONSTER_CAPTURED:
            set_color(BACKGROUND);
            break;
    }
}