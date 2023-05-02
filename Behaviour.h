//
// Created by ainols on 01.05.23.
//

#ifndef SANDSIM_BEHAVIOUR_H
#define SANDSIM_BEHAVIOUR_H

#include <vector>
#include <string>

typedef struct {

    std::vector<std::vector<int>> FallingSquares;
    float Density;  // in g/cm3
    unsigned int ColorR;
    unsigned int ColorG;
    unsigned int ColorB;
    std::string Name;
    bool ShuffleDirections;

} BehaviourType;

class BehaviourGroup {

private:
    std::vector<BehaviourType> Behaviours;

public:
    BehaviourGroup();
    unsigned int AddBehaviour(BehaviourType Behaviour);
    BehaviourType GetBehaviour(unsigned int ID);

};

#endif //SANDSIM_BEHAVIOUR_H
