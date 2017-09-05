FROM siggame/joueur:cpp-onbuild as build

FROM debian:buster-slim

COPY --from=build /tini /tini
COPY --from=build /usr/src/client/build/cpp-client /client/cpp-client
WORKDIR /client

ENTRYPOINT ["/tini", "--", "./cpp-client", "Saloon"]
