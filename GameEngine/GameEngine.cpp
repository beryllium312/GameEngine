#include "GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::GameEngine(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;
	elapsedTime = 0.0f;	
}

void GameEngine::OnCreate()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//IMG_Init(IMG_INIT_PNG);

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);


}
void GameEngine::Update()
{
	typeOfPiece = loadedPieces.vecOfBodies.size();//the map holding the pieces typeOfPiece can be the new key +1
}
void HandleEvents() 
{
	//switch(key) 
	//{
	//	case 1:
	//		currentItem = createCharacter();
	//		createCharacter() 
	//		{
	//			currentImage = charSpite;
	//			currentVector = charVec;
	//		}

	//		OnMouseClick->Body *obj = new Body();
	//		push_back
	//		//or Char *ob
	//
	//
	//}

	//readFileFromDir() {
	//	read the files from a directory;
	//		push each line into a vector;
	//		string fileUserPicked;
	//		std::cout << "Enter number for the file you want" << endl;
	//		cin >> fileUserPicked;
	//		
	//		pickYourFile(int FileUserPicked_) 
	//		{
	//			
	//		}
	//}

}

void GameEngine::populateMap(std::map<int, Body*> bodies_) 
{
	gameMap = bodies_;
}

void GameEngine::Render()
{
	Vec3 screenCoords = projectionMatrix * gameMap.pos;

	SDL_Rect imageRectangle;
	imageRectangle.h = body->getImage()->h;
	imageRectangle.w = body->getImage()->w;
	imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
	imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(body->getImage(), nullptr, screenSurface, &imageRectangle);
	SDL_UpdateWindowSurface(window);

}
void GameEngine::OnDestroy()
{
	if (body) {
		delete body;
		body = nullptr;
	}
}


GameEngine::~GameEngine()
{
}
