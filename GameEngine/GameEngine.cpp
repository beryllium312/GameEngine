#include "GameEngine.h"

GameEngine::GameEngine()
{
}
GameEngine(SDL_Window* sdlWindow_,)
{
	window = sdlWindow_;
	elapsedTime = 0.0f;
}


void OnCreate()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//IMG_Init(IMG_INIT_PNG);

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);


	//map for the made objects


}
void Update() 
{

}
void HandleEvents() 
{
	swtich(key) 
	{
		case 1:
			currentItem = createCharacter();
			createCharacter() 
			{
				currentImage = &charSpite;
				currentVector = &charVec;
			}

			OnMouseClick->Body *obj = new Body();
			push_back
			//or Char *ob
	
	
	}

	readFileFromDir() {
		read the files from a directory;
			push each line into a vector;
			string fileUserPicked;
			std::cout << "Enter number for the file you want" << endl;
			cin >> fileUserPicked;
			
			pickYourFile(int FileUserPicked_) 
			{
				
			}
	}

}
void Render() 
{
	Vec3 screenCoords = projectionMatrix * body->pos;

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
void OnDestroy() 
{
	/*if (body) {
		delete body;
		body = nullptr;
	}*/
}


GameEngine::~GameEngine()
{
}
