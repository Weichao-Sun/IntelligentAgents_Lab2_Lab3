# CP5609 Lab 2

## Overview

This lab extends the Pac-Man C++ project by adding a vector-based board object collection and new board object subclasses.

The main implemented features are:

- `VectorBoardObjects`
- `Monster`
- `Bomb`
- `TestVectorBoardObjects`
- Updated `Makefile.make`
- Doxygen-style comments in new source files

## Main Files

The main modified or added files are located in `PackMan.d/`.

### Added files

- `VectorBoardObjectsH.h`
- `VectorBoardObjects.cpp`
- `MonsterH.h`
- `Monster.cpp`
- `BombH.h`
- `Bomb.cpp`
- `TestVectorBoardObjects.cpp`

### Modified files

- `BoardObjectH.h`
- `Makefile.make`

## VectorBoardObjects

`VectorBoardObjects` is a vector-based collection class for storing `BoardObject*` pointers.

It provides a similar interface to `ListBoardObjects`, but it limits the collection to a maximum of four objects.

Implemented functions include:

- `theFirst()`
- `theNext()`
- `addOne()`
- `removeOnePlayer()`
- `isThereAWall()`
- `isCookieValue()`
- `size()`
- `isFull()`

## Monster and Bomb

`Monster` and `Bomb` are implemented as subclasses of `BoardObject`.

They demonstrate how new game objects can be added to the existing object-oriented structure.

## Compilation

To compile the test program:

```bash
mingw32-make -f Makefile.make TestVectorBoardObjects
