FROM siggame/joueur:cpp-onbuild as build

FROM siggame/joueur:cpp-base

COPY --from=build --chown=siggame:siggame /usr/src/client/build/cpp-client /client/cpp-client
