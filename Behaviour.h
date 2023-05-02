//
// Created by ainols on 01.05.23.
//

#ifndef SANDSIM_BEHAVIOUR_H
#define SANDSIM_BEHAVIOUR_H

#include <vector>
#include <string>

enum BehaviourMoveCheckType {Density, Group};
enum BehaviourMoveType {Swap, Replace};

typedef struct {

    int DX;
    int DY;
    BehaviourMoveCheckType CheckType;
    BehaviourMoveType MoveType;
    std::vector<unsigned int> MoveGroups;

} BehaviourMoveSquare;

typedef struct {

    std::vector<BehaviourMoveSquare> MoveSquares;
    std::vector<unsigned int> Groups;
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
    std::vector<std::string> Groups;

public:
    BehaviourGroup();
    unsigned int AddBehaviour(BehaviourType Behaviour);
    BehaviourType GetBehaviour(unsigned int ID);
    unsigned int AddGroup(std::string GroupName);
    std::string GetGroup(unsigned int ID);
    unsigned int BehaviourCount();
    unsigned int GroupCount();

};

#endif //SANDSIM_BEHAVIOUR_H
