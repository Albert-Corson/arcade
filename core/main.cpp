/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <iostream>
#include <filesystem>
#include "Core.hpp"

void print_usage(const char *bin)
{
    std::cerr << "USAGE" << std::endl;
    std::cerr << "\t" << bin << " path" << std::endl;
    std::cerr << std::endl;
    std::cerr << "DESCRIPTION" << std::endl;
    std::cerr << "\tpath\tpath to graphical library to use by default" << std::endl;
    std::cerr << std::endl;
    std::cerr << "CONTROLS" << std::endl;
    std::cerr << "\tF1\tPrevious library" << std::endl;
    std::cerr << "\tF2\tNext library" << std::endl;
    std::cerr << "\tF3\tPrevious game" << std::endl;
    std::cerr << "\tF4\tNext game" << std::endl;
    std::cerr << "\tF5\tRestart game" << std::endl;
    std::cerr << "\tF6\tBack to menu" << std::endl;
    std::cerr << "\tF7\tExit" << std::endl;
}

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        print_usage(argv[0]);
        return (84);
    }
    try {
        arcade::Core core(std::filesystem::path(MENU_PATH) / "lib_arcade_menu.so", argv[1]);
        core.start();
    } catch (const arcade::Exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
