#include "deltaMergeable.h"

void Joueur::DeltaMergeable::deltaUpdate(boost::property_tree::ptree& delta)
{
    for (auto kv : delta)
    {
        auto fieldName = kv.first;
        this->deltaUpdateField(fieldName, kv.second);
    }
}

void Joueur::DeltaMergeable::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    throw new std::exception("Cannot call deltaUpdateField base directly");
}
