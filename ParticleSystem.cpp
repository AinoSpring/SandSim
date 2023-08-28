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
  RegisterCell(X, Y, Value);

}

void ParticleSystem::RegisterCell(unsigned int X, unsigned int Y, unsigned int Value) {

  if (Value != 0) {

    if (std::find(SetCells.begin(), SetCells.end(), std::vector<unsigned int>({X, Y})) == SetCells.end()) {

      SetCells.push_back({X, Y});

    }

    return;

  }

  SetCells.erase(std::remove(SetCells.begin(), SetCells.end(), std::vector<unsigned int>({X, Y})), SetCells.end());

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

  for (unsigned int I = 0; I < SetCells.size(); I++) {

    int X = SetCells[I][0];
    int Y = SetCells[I][1];

    unsigned int BehaviourID = GetCell(X, Y);

    if (BehaviourID == 0) {

      continue;

    }

    BehaviourType CurrentBehaviourType = Behaviour.GetBehaviour(BehaviourID);

    if (CurrentBehaviourType.ShuffleDirections) {

      std::shuffle(std::begin(CurrentBehaviourType.MoveSquares), std::end(CurrentBehaviourType.MoveSquares), RandomEngine);

    }

    for (unsigned int J = 0; J < CurrentBehaviourType.MoveSquares.size(); J++) {

      BehaviourMoveSquare MoveSquare = CurrentBehaviourType.MoveSquares[J];

      int MoveX = X + MoveSquare.DX;
      int MoveY = Y + MoveSquare.DY;

      if (MoveX < 0 || MoveY < 0 || MoveX >= Width || MoveY >= Height) {

        continue;

      }

      unsigned int NewMoveSquareBehaviourID = NewParticles[MoveX][MoveY];

      BehaviourType NewMoveSquareBehaviourType = Behaviour.GetBehaviour(NewMoveSquareBehaviourID);

      bool Move = false;

      switch (MoveSquare.CheckType) {

        case BehaviourMoveCheckType::Density:
          Move = NewMoveSquareBehaviourType.Density < CurrentBehaviourType.Density;
          break;
        case BehaviourMoveCheckType::Group:
          for (unsigned int K = 0; K < MoveSquare.MoveGroups.size(); K++) {

            if (std::find(NewMoveSquareBehaviourType.Groups.begin(), NewMoveSquareBehaviourType.Groups.end(), MoveSquare.MoveGroups[K]) != NewMoveSquareBehaviourType.Groups.end()) {

              Move = true;
              break;

            }

          }

          break;

      }

      if (Move) {

        switch (MoveSquare.MoveType) {

          case BehaviourMoveType::Swap:
            NewParticles[X][Y] = NewMoveSquareBehaviourID;
            RegisterCell(X, Y, NewMoveSquareBehaviourID);
            NewParticles[MoveX][MoveY] = BehaviourID;
            RegisterCell(MoveX, MoveY, BehaviourID);
            break;
          case BehaviourMoveType::Replace:
            NewParticles[X][Y] = 0;
            RegisterCell(X, Y, 0);
            NewParticles[MoveX][MoveY] = BehaviourID;
            RegisterCell(X, Y, BehaviourID);
            break;

        }

        break;

      }

    }

  }

  Particles = NewParticles;

}
