// Generated by Creer at 04:24PM on March 02, 2016 UTC, git hash: '0cc14891fb0c7c6bec65a23a8e2497e80f8827c1'
// The Spider Queen. She alone can spawn Spiderlings for each Player, and if she dies the owner loses.

#include "broodMother.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::BroodMother::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::Spider::deltaUpdateField(fieldName, delta);

    if (fieldName == "eggs")
    {
        this->eggs = this->gameManager->unserializeFloat(delta);
    }
    else if (fieldName == "health")
    {
        this->health = this->gameManager->unserializeInt(delta);
    }
}



bool Spiders::BroodMother::consume(Spiders::Spiderling* spiderling)
{
    boost::property_tree::ptree args;
    args.put_child("spiderling", *this->gameManager->serialize(spiderling));

    auto returned = this->gameManager->runOnServer(*this, "consume", args);
    return this->gameManager->unserializeBool(*returned);
}

Spiders::Spiderling* Spiders::BroodMother::spawn(std::string spiderlingType)
{
    boost::property_tree::ptree args;
    args.put_child("spiderlingType", *this->gameManager->serialize(spiderlingType));

    auto returned = this->gameManager->runOnServer(*this, "spawn", args);
    return (Spiders::Spiderling*)this->gameManager->unserializeGameObject(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the BroodMother then you can code them here.
// <<-- /Creer-Merge: methods -->>