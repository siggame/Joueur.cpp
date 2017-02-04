// Used to keep cities under control and raid Warehouses.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "policeDepartment.h"
#include "gameManager.h"

#include "warehouse.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::PoliceDepartment::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::Building::deltaUpdateField(fieldName, delta);

}



int Anarchy::PoliceDepartment::raid(Anarchy::Warehouse* warehouse)
{
    boost::property_tree::ptree args;
    args.put_child("warehouse", *this->gameManager->serialize(static_cast<BaseGameObject*>(warehouse)));

    auto returned = this->gameManager->runOnServer(*this, "raid", args);
    return this->gameManager->unserializeInt(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the PoliceDepartment then you can code them here.
// <<-- /Creer-Merge: methods -->>
