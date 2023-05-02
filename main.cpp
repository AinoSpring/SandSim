#include <iostream>
#include "Application.h"

int main() {

    BehaviourGroup Behaviour;

    Behaviour.AddBehaviour({
                                   {},
                                   0,
                                   0,
                                   0,
                                   0,
                                   "Air"
    });

    Behaviour.AddBehaviour({

                                   {
                                           {0, 1},
                                           {1, 1},
                                           {-1, 1}
                                   },
                                   1.52,
                                   198,
                                   166,
                                   100,
                                   "Sand",
                                   false

    });

    Behaviour.AddBehaviour({

                                   {
                                               {0, 1},
                                               {1, 1},
                                               {-1, 1},
                                               {0, 1},
                                               {1, 1},
                                               {-1, 1},
                                               {0, 1},
                                               {1, 1},
                                               {-1, 1},
                                               {1, 0},
                                               {-1, 0}
                                   },
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
