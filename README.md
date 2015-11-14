# Anarchy C++ Client

This is the root of you AI. Stay out of the joueur/ folder, it does most of the heavy lifting to play on our game servers. Your AI, and the game objects it manipulates are all in `games/anarchy/`, with your very own AI living in `games/anarchy/ai.js` for you to make smarter.

## How to Run

This client has been tested and confirmed to work on the Campus rc##xcs213 Linux machines, but it can work on your own Windows/Linux/Mac machines if you desire.

### Linux

```
make
./testRun MyOwnGameSession
```

If you are on your own machine, make sure you've installed boost. The libboost-all-dev package should be up to date. You'll also need cmake for make to work.

### Windows

Be aware that getting this C++ client to build on Windows, while possible, can be a headache.

For Windows, Boost has a simple way to [compile from source using bootstrap](http://www.boost.org/doc/libs/1_58_0/more/getting_started/windows.html). You'll need to do that. This client does work with VC++, you can create a solution at the root or ask a dev for the sln file. Just add the directory you built Boost in the Project's linker configuration. You'll also need to set command line arguments like the other clients.

## Other notes

The initial make step may take upwards of 2 minutes. You should see a percent progress updating on your screen, but it will be slow. Subsequent `make`s should be only a few seconds if you don't `make clean`.
