// Can put out fires completely.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "fireDepartment.h"
#include "gameManager.h"

#include "building.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::FireDepartment::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::Building::deltaUpdateField(fieldName, delta);

    if (fieldName == "fireExtinguished")
    {
        this->fireExtinguished = this->gameManager->unserializeInt(delta);
    }
}



bool Anarchy::FireDepartment::extinguish(Anarchy::Building* building)
{
    boost::property_tree::ptree args;
    args.put_child("building", *this->gameManager->serialize(static_cast<BaseGameObject*>(building)));

    auto returned = this->gameManager->runOnServer(*this, "extinguish", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the FireDepartment then you can code them here.
// <<-- /Creer-Merge: methods -->>
