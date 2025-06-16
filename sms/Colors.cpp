#include "Colors.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <map>
#else
#endif

using namespace std;

void setConsoleColor(const string &colorName)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    map<string, int> colorMap = {
        {"black", 0},
        {"blue", 1},
        {"green", 2},
        {"cyan", 3},
        {"red", 4},
        {"magenta", 5},
        {"yellow", 6},
        {"lightgray", 7},
        {"gray", 8},
        {"lightblue", 9},
        {"lightgreen", 10},
        {"lightcyan", 11},
        {"lightred", 12},
        {"lightmagenta", 13},
        {"lightyellow", 14},
        {"white", 15}};

    auto it = colorMap.find(colorName);
    if (it != colorMap.end())
    {
        SetConsoleTextAttribute(hConsole, it->second);
    }
#else
    map<string, string> ansiMap = {
        {"black", "\033[0;30m"},
        {"red", "\033[0;31m"},
        {"green", "\033[0;32m"},
        {"yellow", "\033[0;33m"},
        {"blue", "\033[0;34m"},
        {"magenta", "\033[0;35m"},
        {"cyan", "\033[0;36m"},
        {"white", "\033[0;37m"},
        {"gray", "\033[1;30m"},
        {"lightred", "\033[1;31m"},
        {"lightgreen", "\033[1;32m"},
        {"lightyellow", "\033[1;33m"},
        {"lightblue", "\033[1;34m"},
        {"lightmagenta", "\033[1;35m"},
        {"lightcyan", "\033[1;36m"},
        {"lightgray", "\033[0;37m"}};

    auto it = ansiMap.find(colorName);
    if (it != ansiMap.end())
    {
        cout << it->second;
    }
#endif
}

void resetConsoleColor()
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}
