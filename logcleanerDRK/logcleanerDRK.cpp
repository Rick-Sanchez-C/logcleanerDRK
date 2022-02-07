#include <iostream>
#include <cstdint>
#include <filesystem>
#include <windows.h>
namespace fs = std::filesystem;
int main()
{
#ifdef _WIN32
    fs::path dir = "C:\\Riot Games\\League of Legends\\Logs";
    if (!fs::exists(dir)) {
        dir = "Logs";
        if (!fs::exists(dir)) {
            std::cout << "You don't have the normal path for Windows you could put this file in (Riot Games/League of legends folder)";
        }
    }
    if (fs::exists(dir)) {
        std::cout << dir;
        fs::create_directories(dir / "abcdef/example");
        std::cout << "Deleting";
        Sleep(10000);
        std::uintmax_t n = fs::remove_all(dir);
        std::cout << "Deleted " << n << " files or directories\n";
    }
    
#endif
#ifdef __APPLE__
    fs::path dir = "/Applications/League of Legends. app/Contents/LOL/Logs";
    if (!fs::exists(dir)) {
        dir = "Logs";
        if (!fs::exists(dir)) {
            std::cout << "You don't have the normal path for Windows you could put this file in (League of legends folder)";
        }
    }
    if (fs::exists(dir)) {
        std::cout << dir;
        fs::create_directories(dir / "abcdef/example");
        std::cout << "Deleting";
        Sleep(10000);
        std::uintmax_t n = fs::remove_all(dir);
        std::cout << "Deleted " << n << " files or directories\n";
    }
#endif
}