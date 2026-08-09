
EXC = VladPackManGame
OBJS = Cookie.o VladPackManGame.o Board.o ListBoardObjects.o Player.o Wall.o
TEST_OBJS = TestVectorBoardObjects.o VectorBoardObjects.o Cookie.o Player.o Wall.o Monster.o Bomb.o
DBG=-g

VladPackManGame : $(OBJS)
	g++ $(DBG)  $(OBJS) -o  VladPackManGame

TestVectorBoardObjects : $(TEST_OBJS)
	g++ $(DBG) $(TEST_OBJS) -o TestVectorBoardObjects

VladPackManGame.o : BoardH.h VladPackManGame.cpp
	g++ $(DBG) -c VladPackManGame.cpp -o VladPackManGame.o 

Player.o : PlayerH.h BoardObjectH.h Player.cpp
	g++ $(DBG) -c Player.cpp -o Player.o 

Wall.o : WallH.h BoardObjectH.h Wall.cpp
	g++ $(DBG) -c Wall.cpp -o Wall.o 

Cookie.o : CookieH.h BoardObjectH.h Cookie.cpp
	g++ $(DBG) -c Cookie.cpp -o Cookie.o 

Board.o : BoardH.h Board.cpp BoardObjectH.h ListBoardObjectsH.h PlayerH.h WallH.h CookieH.h
	g++ $(DBG) -c Board.cpp -o Board.o 

ListBoardObjects.o : ListBoardObjectsH.h BoardObjectH.h ListBoardObjects.cpp PlayerH.h CookieH.h
	g++ $(DBG) -c ListBoardObjects.cpp -o ListBoardObjects.o 

VectorBoardObjects.o : VectorBoardObjectsH.h BoardObjectH.h VectorBoardObjects.cpp PlayerH.h CookieH.h
	g++ $(DBG) -c VectorBoardObjects.cpp -o VectorBoardObjects.o

Monster.o : MonsterH.h BoardObjectH.h Monster.cpp
	g++ $(DBG) -c Monster.cpp -o Monster.o

Bomb.o : BombH.h BoardObjectH.h Bomb.cpp
	g++ $(DBG) -c Bomb.cpp -o Bomb.o

TestVectorBoardObjects.o : TestVectorBoardObjects.cpp BoardObjectH.h CookieH.h PlayerH.h WallH.h MonsterH.h BombH.h VectorBoardObjectsH.h
	g++ $(DBG) -c TestVectorBoardObjects.cpp -o TestVectorBoardObjects.o

clean :
	rm $(OBJS) $(TEST_OBJS) VladPackManGame TestVectorBoardObjects
