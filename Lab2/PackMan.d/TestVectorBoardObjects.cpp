/**
 * @file TestVectorBoardObjects.cpp
 * @brief Test program for VectorBoardObjects, Monster, and Bomb.
 */

#include <iostream>

#include "BoardObjectH.h"
#include "CookieH.h"
#include "PlayerH.h"
#include "WallH.h"
#include "MonsterH.h"
#include "BombH.h"
#include "VectorBoardObjectsH.h"

using namespace std;

/**
 * @brief Converts an ObjectTypes value into readable text.
 */
const char* typeName(ObjectTypes type)
{
    switch (type)
    {
        case THE_BACKGROUND:
            return "background";
        case A_COOKIE:
            return "cookie";
        case A_PLAYER:
            return "player";
        case A_WALL:
            return "wall";
        case A_MONSTER:
            return "monster";
        case A_BOMB:
            return "bomb";
        default:
            return "unknown";
    }
}

/**
 * @brief Prints all objects stored in the VectorBoardObjects collection.
 */
void printObjects(VectorBoardObjects& objects)
{
    BoardObject* current = objects.theFirst();

    while (current != NULL)
    {
        cout << "Object type: " << typeName(current->get_Type())
             << " at cell (" << current->get_x()
             << "," << current->get_y() << ")" << endl;

        current = objects.theNext();
    }
}

int main()
{
    cout << "=== VectorBoardObjects Test ===" << endl;

    Monster aMonster(1, 1);
    Bomb aBomb(2, 2);
    Cookie aCookie(3, 3);
    Wall aWall(4, 4);
    Player aPlayer(5, 5);

    VectorBoardObjects objects(&aMonster);

    objects.addOne(&aBomb);
    objects.addOne(&aCookie);
    objects.addOne(&aWall);

    cout << "Initial collection:" << endl;
    printObjects(objects);

    cout << "Current size: " << objects.size() << endl;
    cout << "Is full: " << objects.isFull() << endl;

    cout << endl;
    cout << "Trying to add a fifth object..." << endl;
    objects.addOne(&aPlayer);

    cout << "Size after trying to add fifth object: "
         << objects.size() << endl;

    cout << endl;
    cout << "Wall exists: " << objects.isThereAWall() << endl;

    cout << "Cookie value collected: "
         << objects.isCookieValue() << endl;

    cout << "Size after removing cookie: "
         << objects.size() << endl;

    cout << endl;
    cout << "Adding player after cookie was removed..." << endl;
    objects.addOne(&aPlayer);

    cout << "Collection after adding player:" << endl;
    printObjects(objects);

    cout << "Removing one player..." << endl;
    objects.removeOnePlayer();

    cout << "Final collection:" << endl;
    printObjects(objects);

    cout << "Final size: " << objects.size() << endl;

    return 0;
}