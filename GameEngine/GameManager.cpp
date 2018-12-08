#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Assignment1.h"
#include "Assignment2.h"
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
	//start = false;
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 1080;
	const int SCREEN_HEIGHT = 680;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new Assignment1(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	SDL_Event event; //hold events
	timer->Start();
	while (isRunning) {
		if (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
				
			case SDL_QUIT:
				printf("Got a quit event \n");
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_F2) {
					
					currentScene->OnDestroy();//cleans up what being used currently
					delete currentScene;
					currentScene = nullptr;//make it null
					currentScene = new Assignment1(ptr->GetSDL_Window());//
					currentScene->OnCreate(); 
					//start = false;
				}
				if (event.key.keysym.sym == SDLK_F3) {
					
					currentScene->OnDestroy();//cleans up what being used currently
					delete currentScene;
					currentScene = nullptr;//make it null
					currentScene = new Assignment2(ptr->GetSDL_Window());//
					currentScene->OnCreate(); 
					//start = false;

				}				
				break;
			}

			
			currentScene->HandleEvents(event);
		}
		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec

	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy() {
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}