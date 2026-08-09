/**
 * @file VectorBoardObjects.cpp
 * @brief Implementation of the VectorBoardObjects class.
 */

#include <iostream>
#include "BoardObjectH.h"
#include "CookieH.h"
#include "PlayerH.h"
#include "VectorBoardObjectsH.h"

VectorBoardObjects::VectorBoardObjects(BoardObject* theFirstObject) : list()
{
    if (theFirstObject != NULL)
    {
        list.push_back(theFirstObject);
    }

    internalIterator = list.begin();
}

BoardObject* VectorBoardObjects::theFirst()
{
    if (list.size() > 0)
    {
        internalIterator = list.begin();
        return (*internalIterator);
    }

    return NULL;
}

BoardObject* VectorBoardObjects::theNext()
{
    if (list.size() == 0)
    {
        return NULL;
    }

    internalIterator++;

    if (internalIterator != list.end())
    {
        return (*internalIterator);
    }

    return NULL;
}

void VectorBoardObjects::addOne(BoardObject* newOne)
{
    if (newOne == NULL)
    {
        return;
    }

    if (list.size() < MAX_OBJECTS)
    {
        list.push_back(newOne);
    }
    else
    {
        std::cerr << "VectorBoardObjects is full. Object was not added." << std::endl;
    }
}

void VectorBoardObjects::removeOnePlayer()
{
    std::vector<BoardObject*>::iterator it = list.begin();

    while (it != list.end())
    {
        if (A_PLAYER == (*it)->get_Type())
        {
            list.erase(it);
            return;
        }

        it++;
    }
}

bool VectorBoardObjects::isThereAWall()
{
    std::vector<BoardObject*>::iterator it = list.begin();

    while (it != list.end())
    {
        if (A_WALL == (*it)->get_Type())
        {
            return true;
        }

        it++;
    }

    return false;
}

int VectorBoardObjects::isCookieValue()
{
    int temp = 0;
    std::vector<BoardObject*>::iterator it = list.begin();

    while (it != list.end())
    {
        if (A_COOKIE == (*it)->get_Type())
        {
            temp = ((Cookie *)(*it))->get_value();
            list.erase(it);
            return temp;
        }

        it++;
    }

    return temp;
}

int VectorBoardObjects::size()
{
    return list.size();
}

bool VectorBoardObjects::isFull()
{
    return list.size() >= MAX_OBJECTS;
}
