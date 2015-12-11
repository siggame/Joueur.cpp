#ifndef JOUEUR_ANSICOLORCODER_H
#define JOUEUR_ANSICOLORCODER_H

#include "joueur.h"

namespace Joueur
{
    enum class ANSIColorCoder
    {
        None = 0,
        Reset = 0,
        Bold = 1,
        Underline = 4,
        Blink = 5,
        Inverse = 7,
        Hidden = 8,

        BlackText = 30,
        RedText = 31,
        GreenText = 32,
        YellowText = 33,
        BlueText = 34,
        MagentaText = 35,
        CyanText = 36,
        WhiteText = 37,
        DefaultText = 39,

        BlackBackground = 40,
        RedBackground = 41,
        GreenBackground = 42,
        YellowBackground = 43,
        BlueBackground = 44,
        MagentaBackground = 45,
        CyanBackground = 46,
        WhiteBackground = 47,
        DefaultBackground = 49
    };

    // << overload, cor cout/cerr
    static std::ostream& operator<<(std::ostream& os, ANSIColorCoder code)
    {
        os << ((char)27) << "[" << static_cast<int>(code) << "m";
        return os;
    };
}

#endif
