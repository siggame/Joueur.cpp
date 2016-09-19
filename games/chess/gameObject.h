// An object in the game. The most basic class that all game classes should inherit from automatically.

#ifndef JOUEUR_CHESS_GAMEOBJECT_H
#define JOUEUR_CHESS_GAMEOBJECT_H

#include "chess.h"
#include "../../joueur/baseGameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// An object in the game. The most basic class that all game classes should inherit from automatically.
/// </summary>
class Chess::GameObject : public Joueur::BaseGameObject
{
    friend Chess::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        GameObject() {};
        ~GameObject() {};

    public:
        /// <summary>
        /// Any strings logged will be stored here. Intended for debugging.
        /// </summary>
        std::vector<std::string> logs;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Adds a message to this GameObject's logs. Intended for your own debugging purposes, as strings stored here are saved in the gamelog.
        /// </summary>
        /// <param name="message">A string to add to this GameObject's log. Intended for debugging.</param>
        void log(std::string message);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
