#pragma once

#ifdef FOUNDRY_WINDOWS
#define START_FOUNDRY_GAME(GameClass) \
    int WinMain()                  \
    {                              \
        GameClass game;            \
        game.run();                \
        return 0;                  \
    }
#else
#define START_FOUNDRY_GAME(GameClass) \
    int main()                     \
    {                              \
        GameClass game;            \
        game.run();                \
        return 0;                  \
    }
#endif

#ifdef FOUNDRY_WINDOWS
    #ifdef FOUNDRY_LIB
        #define FOUNDRY_API __declspec(dllexport)
    #else
        #define FOUNDRY_API __declspec(dllimport)
    #endif
#else
    #define FOUNDRY_API
#endif

#ifdef FOUNDRY_DEBUG
    #define FOUNDRY_LOG(x) std::cout << x << std::endl
#else
    #define FOUNDRY_LOG(x)
#endif