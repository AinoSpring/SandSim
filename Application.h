//
// Created by ainols on 30.04.23.
//

#ifndef SANDSIM_APPLICATION_H
#define SANDSIM_APPLICATION_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "ParticleSystem.h"
#include "Behaviour.h"

class Application {
private:
    bool Running;
    std::string Title;
    unsigned int Width;
    unsigned int Height;
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    unsigned int CurrentType = 1;

public:
    Application(std::string Title, unsigned int Width, unsigned int Height, BehaviourGroup Behaviour);
    int OnExecute();

public:
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

public:
    ParticleSystem ParticleSys;

};


#endif //SANDSIM_APPLICATION_H
