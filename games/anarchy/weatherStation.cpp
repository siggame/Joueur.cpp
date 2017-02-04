// Can be bribed to change the next Forecast in some way.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "weatherStation.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::WeatherStation::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::Building::deltaUpdateField(fieldName, delta);

}



bool Anarchy::WeatherStation::intensify(bool negative)
{
    boost::property_tree::ptree args;
    args.put_child("negative", *this->gameManager->serialize((negative)));

    auto returned = this->gameManager->runOnServer(*this, "intensify", args);
    return this->gameManager->unserializeBool(*returned);
}

bool Anarchy::WeatherStation::rotate(bool counterclockwise)
{
    boost::property_tree::ptree args;
    args.put_child("counterclockwise", *this->gameManager->serialize((counterclockwise)));

    auto returned = this->gameManager->runOnServer(*this, "rotate", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the WeatherStation then you can code them here.
// <<-- /Creer-Merge: methods -->>
