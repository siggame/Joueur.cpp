// A chess piece.

#include "piece.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Chess::Piece::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Chess::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "captured")
    {
        this->captured = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "file")
    {
        this->file = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "hasMoved")
    {
        this->hasMoved = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Chess::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "rank")
    {
        this->rank = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "type")
    {
        this->type = this->gameManager->unserializeString(delta);
    }
}



Chess::Move* Chess::Piece::move(std::string file, int rank, std::string promotionType)
{
    boost::property_tree::ptree args;
    args.put_child("file", *this->gameManager->serialize((file)));
    args.put_child("rank", *this->gameManager->serialize((rank)));
    args.put_child("promotionType", *this->gameManager->serialize((promotionType)));

    auto returned = this->gameManager->runOnServer(*this, "move", args);
    return (Chess::Move*)this->gameManager->unserializeGameObject(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Piece then you can code them here.
// <<-- /Creer-Merge: methods -->>
