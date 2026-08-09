#ifndef H_VECTOR_OF_OBJECTS
#define H_VECTOR_OF_OBJECTS

#include <vector>
#include "BoardObjectH.h"
#include "PlayerH.h"
#include "CookieH.h"

/**
 * @brief VectorBoardObjects stores BoardObject pointers using a vector.
 *
 * This class provides a similar interface to ListBoardObjects, but it limits
 * the collection to a maximum of four objects. It is used to test whether the
 * list-based implementation can be replaced by a vector-based implementation
 * with only localized changes.
 */
class VectorBoardObjects
{
private:
    enum { MAX_OBJECTS = 4 };

    std::vector<BoardObject*> list;
    std::vector<BoardObject*>::iterator internalIterator;

public:
    /**
     * @brief Constructs the collection with one initial object.
     * @param theFirst The first BoardObject pointer stored in the vector.
     */
    VectorBoardObjects(BoardObject* theFirst);

    /**
     * @brief Returns the first object in the collection and resets the iterator.
     * @return Pointer to the first object, or NULL if the vector is empty.
     */
    BoardObject* theFirst();

    /**
     * @brief Returns the next object after the current iterator position.
     * @return Pointer to the next object, or NULL if there are no more objects.
     */
    BoardObject* theNext();

    /**
     * @brief Adds one object to the vector if the capacity is not full.
     * @param newOne The object pointer to add.
     */
    void addOne(BoardObject* newOne);

    /**
     * @brief Removes one player object from the vector if one exists.
     */
    void removeOnePlayer();

    /**
     * @brief Checks whether the vector contains a wall.
     * @return true if a wall exists, otherwise false.
     */
    bool isThereAWall();

    /**
     * @brief Returns the value of one cookie and removes that cookie.
     * @return Cookie value if a cookie exists, otherwise 0.
     */
    int isCookieValue();

    /**
     * @brief Returns the current number of objects in the vector.
     * @return Number of stored objects.
     */
    int size();

    /**
     * @brief Checks whether the vector has reached its maximum capacity.
     * @return true if the vector contains four objects, otherwise false.
     */
    bool isFull();
};

#endif