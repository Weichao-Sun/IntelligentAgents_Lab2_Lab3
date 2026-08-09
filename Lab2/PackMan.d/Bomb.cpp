/**
 * @file Bomb.cpp
 * @brief Implementation of the Bomb class.
 */

#include "BoardObjectH.h"
#include "BombH.h"

Bomb::Bomb(int start_x, int start_y) : BoardObject(start_x, start_y)
{
    status = BOMB_ACTIVE;
    color1 = BLACK;
    color2 = RED;
    myClass = A_BOMB;
}

void Bomb::touch()
{
    switch (status)
    {
        case BOMB_ACTIVE:
            if (color1 == get_Color())
                set_color(color2);
            else
                set_color(color1);
            break;

        case BOMB_USED:
            set_color(BACKGROUND);
            break;
    }
}