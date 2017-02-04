// An object in the game. The most basic class that all game classes should inherit from automatically.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_CHECKERS_GAMEOBJECT_H
#define JOUEUR_CHECKERS_GAMEOBJECT_H

#include "checkers.h"
#include "../../joueur/baseGameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// An object in the game. The most basic class that all game classes should inherit from automatically.
/// </summary>
class Checkers::GameObject : public Joueur::BaseGameObject
{
    friend Checkers::GameManager;

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
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Adds a message to this GameObject's logs. Intended for your own debugging purposes, as strings stored here are saved in the gamelog.
        /// </summary>
        /// <param name="message">A string to add to this GameObject's log. Intended for debugging.</param>
        void log(std::string message);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
