// Generated by Creer at 04:24PM on March 02, 2016 UTC, git hash: '0cc14891fb0c7c6bec65a23a8e2497e80f8827c1'
// A Spiderling that can cut existing Webs.

#include "cutter.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Cutter::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::Spiderling::deltaUpdateField(fieldName, delta);

    if (fieldName == "cuttingWeb")
    {
        this->cuttingWeb = (Spiders::Nest*)this->gameManager->unserializeGameObject(delta);
    }
}



bool Spiders::Cutter::cut(Spiders::Web* web)
{
    boost::property_tree::ptree args;
    args.put_child("web", *this->gameManager->serialize(web));

    auto returned = this->gameManager->runOnServer(*this, "cut", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Cutter then you can code them here.
// <<-- /Creer-Merge: methods -->>