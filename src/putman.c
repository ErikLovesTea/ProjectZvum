//
// Created by zvum on 3/16/26.
//

#include <SDL3/SDL.h>

#include "mainmenu.h"

void registerInput(SDL_Event *event) {
    if (event->key.scancode == SDL_SCANCODE_ESCAPE) {
        SDL_Event quitEvent;
        quitEvent.type = SDL_EVENT_QUIT;
        SDL_PushEvent(&quitEvent);
    }

    // rest of keyboard here
}

void registerMouse(const SDL_Event *event) {
    SDL_FPoint mousePos = {event->button.x, event->button.y};
    if (SDL_PointInRectFloat(&mousePos, &playBtnFRect)) {
        SDL_Log("Play button clicked!");
        // Handle play button click
    } else if (SDL_PointInRectFloat(&mousePos, &settingsBtnFRect)) {
        SDL_Log("Settings button clicked!");
        // Handle settings button click
    }
}