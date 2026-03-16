#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include "mainmenu.h"

SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;

const char *title = "Project Zvum Development Preview";

const int windowWidth = 1280;
const int windowHeight = 720;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){

	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl"); // Windows usually goes for directx first,
	// and I don't have the slightest of a clue if they'll differ or not since I'm on opengl
	
	mainWindow = SDL_CreateWindow(title, windowWidth, windowHeight, 0);
	if (mainWindow == NULL){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	mainRenderer = SDL_CreateRenderer(mainWindow, NULL);
	if (mainRenderer == NULL){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	init_main_menu();

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if (event->type == SDL_EVENT_QUIT){
		return SDL_APP_SUCCESS;
	}

	if (event->type == SDL_EVENT_KEY_DOWN) {
		registerInput(event);
	}

	if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
		registerMouse(event);
	}

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate){
	SDL_RenderClear(mainRenderer);

	if (texturesLoaded == true){
		SDL_RenderTexture(mainRenderer, playBtnTexture, NULL, &playBtnFRect);
		SDL_RenderRect(mainRenderer, &playBtnFRect);

		SDL_RenderTexture(mainRenderer, settingsBtnTexture, NULL, &settingsBtnFRect);
		SDL_RenderRect(mainRenderer, &settingsBtnFRect);
	}

	SDL_RenderPresent(mainRenderer);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result){
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION ,"Exiting program...");
}
