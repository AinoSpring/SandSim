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

unsigned int BehaviourGroup::AddGroup(std::string GroupName) {

    Groups.push_back(GroupName);

    return Groups.size() - 1;

}

std::string BehaviourGroup::GetGroup(unsigned int ID) {

    return Groups[ID];

}

unsigned int BehaviourGroup::BehaviourCount() {

    return Behaviours.size();

}

unsigned int BehaviourGroup::GroupCount() {

    return Groups.size();

}
