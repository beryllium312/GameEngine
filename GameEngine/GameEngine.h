#pragma once
#include "MMath.h"
#include "Scene.h"
#include "Body.h" 
#include <map>
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

private:
	SDL_Window * window;
	Matrix4 projectionMatrix;	
	float elapsedTime = 0.0f;
	unsigned long frameCount = 0.0L;

public:
	GameEngine();
	GameEngine(SDL_Window* sdlWindow_);
	void OnCreate();
	void Update();
	void HandleEvents();
	void Render();
	void OnDestroy();
	~GameEngine();
};

