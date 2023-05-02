//
// Created by ainols on 30.04.23.
//

#include "Application.h"
#include "ParticleSystem.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <sstream>

Application::Application(std::string Title, unsigned int Width, unsigned int Height, BehaviourGroup Behaviour)
: Title(Title), Width(Width), Height(Height), Window(NULL), Running(true), ParticleSys(Width, Height, Behaviour)
{


}

int Application::OnExecute() {

    if(OnInit() == false) {

        return -1;

    }

    SDL_Event Event;

    while(Running) {

        while(SDL_PollEvent(&Event)) {

            OnEvent(&Event);

        }

        OnLoop();
        OnRender();

    }

    OnCleanup();

    return 0;

}

bool Application::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    SDL_CreateWindowAndRenderer(Width, Height, 0, &Window, &Renderer);
    SDL_SetWindowTitle(Window, Title.c_str());

    if(Window == NULL) {
        return false;
    }

    return true;

}

void Application::OnEvent(SDL_Event *Event) {

    switch (Event->type) {
        case SDL_QUIT:
            Running = false;
            break;
        case SDL_KEYDOWN:
            for (int Key = 0; Key < 10; Key++) {

                std::stringstream StringKey;
                StringKey << Key;
                if (Event->key.keysym.sym == StringKey.str().c_str()[0]) {

                    CurrentType = Key;
                    break;

                }

            }
            break;

    }

}

void Application::OnLoop() {

    int X;
    int Y;

    if (SDL_GetMouseState(&X, &Y) & SDL_BUTTON_LMASK) {

        if (!(X < 0 || Y < 0 || X >= Width || Y >= Height)) {

            ParticleSys.SetCell(X, Y, CurrentType);

        }

    }

    ParticleSys.UpdateParticles();

}

void Application::OnRender() {

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);

    SDL_RenderClear(Renderer);

    for (unsigned int X = 0; X < Width; X++) {

        for (unsigned int Y = 0; Y < Height; Y++) {

            unsigned int BehaviourID = ParticleSys.GetCell(X, Y);

            BehaviourType CurrentBehaviour = ParticleSys.Behaviour.GetBehaviour(BehaviourID);

            SDL_SetRenderDrawColor(Renderer, CurrentBehaviour.ColorR, CurrentBehaviour.ColorG, CurrentBehaviour.ColorB, 255);

            SDL_RenderDrawPoint(Renderer, X, Y);

        }

    }

    SDL_RenderPresent(Renderer);

}

void Application::OnCleanup() {

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();

}