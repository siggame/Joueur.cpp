// A Spiderling that can cut existing Webs.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "cutter.h"
#include "gameManager.h"

#include "web.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Cutter::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::Spiderling::deltaUpdateField(fieldName, delta);

    if (fieldName == "cuttingWeb")
    {
        this->cuttingWeb = (Spiders::Web*)this->gameManager->unserializeGameObject(delta);
    }
}



bool Spiders::Cutter::cut(Spiders::Web* web)
{
    boost::property_tree::ptree args;
    args.put_child("web", *this->gameManager->serialize(static_cast<BaseGameObject*>(web)));

    auto returned = this->gameManager->runOnServer(*this, "cut", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Cutter then you can code them here.
// <<-- /Creer-Merge: methods -->>
