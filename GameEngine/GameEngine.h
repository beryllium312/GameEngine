#pragma once
#include "MMath.h"
#include "Scene.h"
#include "Body.h" 
#include "LoadFile.h" 
#include <map>
#include <vector>
#include <SDL.h>
#include "SDL_image.h"
#include <windows.h>//might need for directory reader

using namespace MATH;
using namespace std;

class GameEngine
{
private:
	int typeOfPiece;
	string imageName;	
	Vec3 positionVec;

public:
	class LoadFile loadedPieces;
private:
	SDL_Window * window;
	Matrix4 projectionMatrix;	
	float elapsedTime = 0.0f;
	unsigned long frameCount = 0.0L;

	std::map<int, Body*> gameMap;
	//std::vector<Body*> invBtns;

	std::string folder;
	std::vector<std::string> uiItems;
	std::vector<Vec3> position;

public:
	GameEngine();
	GameEngine(SDL_Window* sdlWindow_);
	void OnCreate();
	void Update();
	void HandleEvents();
	void Render();
	void OnDestroy();
	void populateMap(std::map<int, Body*> bodies_);
	void getObjectMap(std::vector<std::string> uiItems_, std::vector<Vec3> position_);
	~GameEngine();
};

