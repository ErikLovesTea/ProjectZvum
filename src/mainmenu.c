#include <SDL3/SDL.h>
#include <stdio.h>
#include "main.h"

/*
extern int _DebugMode;
extern SDL_Window* mainWindow;
extern SDL_Renderer* mainRenderer;
*/

//extern SDL_Window* mainWindow;
//extern SDL_Renderer* mainRenderer;

char *playBtn = "assets/playbutton.bmp";
SDL_Surface* playBtnSurface;
SDL_Texture* playBtnTexture;

char *settingsBtn = "assets/settingsbutton.bmp";
SDL_Surface* settingsBtnSurface;
SDL_Texture* settingsBtnTexture;

SDL_FRect playBtnFRect;
SDL_FRect settingsBtnFRect;

const float globalGUIWidth = 100.0f;
const float globalGUIHeight = 100.0f;


bool texturesLoaded = false;

/*
SDL_FRect playBtnFRect = {
	.x = 100,
	.y = 100,
	.w = 50,
	.h = 50
};
*/

typedef struct {
	float x;
	float y;

} screenSize;

//screenSize temp; //just remember to uncomment this if it fails to compile again ffs

bool loadTextures();
screenSize calculateLayout();


bool init_main_menu(){
	playBtnFRect.w = globalGUIWidth;
	playBtnFRect.h = globalGUIHeight;
	settingsBtnFRect.w = globalGUIWidth;
	settingsBtnFRect.h = globalGUIHeight;

	loadTextures();

	const screenSize guiLocation = calculateLayout();

	playBtnFRect.x = guiLocation.x;
	playBtnFRect.y = guiLocation.y - 50.0f;
	settingsBtnFRect.x = guiLocation.x;
	settingsBtnFRect.y = guiLocation.y + 50.0f; // padding

	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Textures loaded true");

	texturesLoaded = true;

	return 1;
}


bool loadTextures(){
	playBtnSurface = SDL_LoadBMP(playBtn);
	playBtnTexture = SDL_CreateTextureFromSurface(mainRenderer, playBtnSurface);

	settingsBtnSurface = SDL_LoadBMP(settingsBtn);
	settingsBtnTexture = SDL_CreateTextureFromSurface(mainRenderer, settingsBtnSurface);

	if (playBtnSurface == NULL || settingsBtnSurface == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load: %s", SDL_GetError());
	}
	if (playBtnTexture == NULL || settingsBtnTexture == NULL){
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "play button texture failed: %s", SDL_GetError());
	}



	return 1;
}

screenSize calculateLayout(){
	int width, height;
	SDL_GetWindowSizeInPixels(mainWindow, &width, &height);

	screenSize temp = {
		((float)width / 2.0f) - (playBtnFRect.w / 2),
		((float)height / 2.0f) - (playBtnFRect.h / 2)
	    };

	return temp;
}
