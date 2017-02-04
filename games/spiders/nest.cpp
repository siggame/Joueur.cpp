// A location (node) connected to other Nests via Webs (edges) in the game that Spiders can converge on, regardless of owner.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "nest.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Nest::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "spiders")
    {
        this->spiders = this->gameManager->unserializeVectorOfGameObjects<Spiders::Spider*>(delta, &this->spiders);
    }
    else if (fieldName == "webs")
    {
        this->webs = this->gameManager->unserializeVectorOfGameObjects<Spiders::Web*>(delta, &this->webs);
    }
    else if (fieldName == "x")
    {
        this->x = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "y")
    {
        this->y = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Nest then you can code them here.
// <<-- /Creer-Merge: methods -->>
