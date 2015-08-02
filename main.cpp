#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "joueur/client.h"
#include "joueur/baseGame.h"
#include "currentGame.h"

using namespace std;

int main()
{
    string gameName = "Checkers";
    string server = "localhost";
    int port = 3000;
    bool printIO = true;

    cout << "hi" << endl;

    Joueur::Client *client = Joueur::Client::getInstance();

    CurrentGame c = getCurrentGame(gameName);

    Joueur::BaseGame* game = c.game;
    Joueur::BaseAI* ai = c.ai;

    return 0;
}
