//
// Created by ainols on 30.04.23.
//

#include <iostream>
#include <algorithm>
#include <random>
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int Width, unsigned int Height, BehaviourGroup Behaviour)
: Width(Width), Height(Height), Behaviour(Behaviour), RandomEngine(std::default_random_engine {})
{

     for (unsigned int X = 0; X < Width; X++) {

         std::vector<unsigned int> Row(Height);
         Particles.push_back(Row);

     }

}

void ParticleSystem::SetCell(unsigned int X, unsigned int Y, unsigned int Value) {

    Particles[X][Y] = Value;

}

unsigned int ParticleSystem::GetCell(unsigned int X, unsigned int Y) {

    return Particles[X][Y];

}

std::vector<std::vector<unsigned int>> ParticleSystem::CopyParticles() {

    std::vector<std::vector<unsigned int>> CopiedParticles;
    for (unsigned int X = 0; X < Particles.size(); X++) {

        std::vector<unsigned int> Row;

        for (unsigned int Y = 0; Y < Particles[X].size(); Y++) {

            Row.push_back(Particles[X][Y]);

        }

        CopiedParticles.push_back(Row);

    }

    return CopiedParticles;

}

void ParticleSystem::UpdateParticles() {

    std::vector<std::vector<unsigned int>> NewParticles = CopyParticles();

    for (int X = 0; X < Width; X++) {

        for (int Y = 0; Y < Height; Y++) {

            unsigned int BehaviourID = Particles[X][Y];

            if (BehaviourID == 0) {

                continue;

            }

            BehaviourType CurrentBehaviourType = Behaviour.GetBehaviour(BehaviourID);

            if (CurrentBehaviourType.ShuffleDirections) {

                std::shuffle(std::begin(CurrentBehaviourType.FallingSquares), std::end(CurrentBehaviourType.FallingSquares), RandomEngine);

            }

            for (unsigned int I = 0; I < CurrentBehaviourType.FallingSquares.size(); I ++) {

                int DX = CurrentBehaviourType.FallingSquares[I][0];
                int DY = CurrentBehaviourType.FallingSquares[I][1];

                int FallingX = X + DX;
                int FallingY = Y + DY;

                if (FallingX < 0 || FallingY < 0 || FallingX >= Width || FallingY >= Height) {

                    continue;

                }

                unsigned int FallingSquareBehaviourID = Particles[FallingX][FallingY];

                if (FallingSquareBehaviourID != NewParticles[FallingX][FallingY]) {

                    continue;

                }

                BehaviourType FallingSquareBehaviourType = Behaviour.GetBehaviour(FallingSquareBehaviourID);

                if (FallingSquareBehaviourType.Density < CurrentBehaviourType.Density) {

                    NewParticles[X][Y] = FallingSquareBehaviourID;
                    NewParticles[FallingX][FallingY] = BehaviourID;

                    break;

                }

            }

        }

    }

    Particles = NewParticles;

}