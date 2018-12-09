#pragma once

#include "Body.h"
#include "Vector.h"
#include "GameEngine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace MATH;
using namespace std;

class LoadFile
{
public:
	std::string characterSpriteName;
	std::string EnemySpriteName;
	std::string LandSpriteName;
	Vec3 CharacterVector;
	Vec3 EnemyVector;
	Vec3 LandVector;
	GameEngine gameEng;
	std::map<int, Body*> vecOfBodies;

public:
	LoadFile();
	LoadFile(const char * fileName);
	~LoadFile();	
private:
	void LoadObj(const char * fileName);
	float iterateVect(std::string nextLine);
	int iterateRect(std::string nextLine);
	void makeGamePiece(std::string imageFile_, Vec3 objVector_, int typeOfPiece_);
	
};
