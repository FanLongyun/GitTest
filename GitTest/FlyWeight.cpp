// FlyWeight.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

class Game
{
public:
	string name;
	string platform;
	float price;
};

class client
{
public:
	map<int, Game> myGames;
	Game* getGame(int key)
	{
		map<int, Game>::iterator iter = myGames.find(key);
		if (iter != myGames.end())
		{
			return &iter->second;
		}
		else
		{
			Game *one = new Game;
			pair<int, Game> pGa;
			pGa.first = key;
			pGa.second = *one;
			myGames.insert(pGa);
			return one;
		}
	}
};

int main()
{
    return 0;
}

