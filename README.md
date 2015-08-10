# Joueur.cpp
The C++ game client for the Cadre framework to connect to [Cerveau](https://github.com/JacobFischer/Cerveau) servers.

![{Cadre}](http://i.imgur.com/17wwI3f.png)

All inspiration taken from [MST's SIG-GAME framework](https://github.com/siggame), and most of the terminology is assuming some familiarity with it as this is a spiritual successor to it.

## Features

* Multi-Game:
  * One client can have multiple AIs to play different games.
* Easy generation of new game AIs using the [Creer](https://github.com/JacobFischer/Creer) codegen.
* No game specific logic. All logic is done server side. Here on clients we just merge deltas into the game state, and expose the changes in handle Game and GameObject classes.
* Compiles under VC++ and GCC. Included is a Visual Studio solution for convenience.
* Requires [Boost](http://www.boost.org/), the incredible popular C++ library package.
* Networking via TCP
  * Communication via json strings with support for cycles within game references
  * Only deltas in states are send over the network

## How to Run

```
a.out GAME_NAME -s SERVER -p PORT -n PLAYER_NAME
```

Only `GAME_NAME` is required to run this client.


## Other notes

C++ is the only client that can not do reflection (A language limitation). Most of that limitation is handled by the Creer templates, but when new games are added there is no way for the main function to know. Just register the game in `currentGame.h` as the others are registered. The Creer templates should handle the rest of the "reflection".
