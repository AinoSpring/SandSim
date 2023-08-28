#include <iostream>
#include "Application.h"

int main() {

  BehaviourGroup Behaviour;

  Behaviour.AddGroup("Fluid");
  Behaviour.AddGroup("Solid");

  Behaviour.AddBehaviour({
      {},
      {0},
      0,
      0,
      0,
      0,
      "Air"
      });

  Behaviour.AddBehaviour({

      {
      {0, 1, Density, Swap},
      {1, 1, Density, Swap},
      {-1, 1, Density, Swap}
      },
      {1},
      1.52,
      198,
      166,
      100,
      "Sand",
      false

      });

  Behaviour.AddBehaviour({

      {
      {0, 1, Density, Swap},
      {1, 1, Density, Swap},
      {-1, 1, Density, Swap},
      {0, 1, Density, Swap},
      {1, 1, Density, Swap},
      {-1, 1, Density, Swap},
      {0, 1, Density, Swap},
      {1, 1, Density, Swap},
      {-1, 1, Density, Swap},
      {1, 0, Density, Swap},
      {-1, 0, Density, Swap}
      },
      {0},
      1,
      9,
      195,
      219,
      "Water",
      true

  });

  Application application("Sand", 800, 600, Behaviour);

  application.OnExecute();

  return 0;
}
