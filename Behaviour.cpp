//
// Created by ainols on 01.05.23.
//

#include "Behaviour.h"

BehaviourGroup::BehaviourGroup() {



}

unsigned int BehaviourGroup::AddBehaviour(BehaviourType Behaviour) {

    Behaviours.push_back(Behaviour);

    return Behaviours.size() - 1;

}

BehaviourType BehaviourGroup::GetBehaviour(unsigned int ID) {

    return Behaviours[ID];

}