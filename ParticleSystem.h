//
// Created by ainols on 30.04.23.
//

#ifndef SANDSIM_PARTICLESYSTEM_H
#define SANDSIM_PARTICLESYSTEM_H

#include <vector>
#include <algorithm>
#include <random>
#include "Behaviour.h"

class ParticleSystem {
private:
    unsigned int Width;
    unsigned int Height;
    std::vector<std::vector<unsigned int>> Particles;
    std::vector<std::vector<unsigned int>> SetCells;
    std::linear_congruential_engine<uint_fast32_t, 16807UL, 0UL, 2147483647UL> RandomEngine;

public:
    ParticleSystem(unsigned int Width, unsigned int Height, BehaviourGroup Behaviour);
    void SetCell(unsigned int X, unsigned int Y, unsigned int Value);
    void RegisterCell(unsigned int X, unsigned int Y, unsigned int Value);
    unsigned int GetCell(unsigned int X, unsigned int Y);
    std::vector<std::vector<unsigned int>> CopyParticles();
    void UpdateParticles();
    BehaviourGroup Behaviour;

};

#endif //SANDSIM_PARTICLESYSTEM_H
