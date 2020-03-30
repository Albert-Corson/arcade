/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibGraphNcurses
*/

#include "LibGraphNcurses.hpp"
#include "NcursesKeys.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

using namespace arcade;

std::unique_ptr<ILibGraph> init_graph_lib()
{
    return (std::make_unique<LibGraphNcurses>());
}

LibGraphNcurses::Image::Image(const std::string &img)
    : image(img)
    , posX(0)
    , posY(0)
{
}

LibGraphNcurses::Image::Image(const Image &other)
{
    *this = other;
}

void LibGraphNcurses::Image::operator=(const Image &other)
{
    image = other.image;
    posX = other.posX;
    posY = other.posY;
}

LibGraphNcurses::LibGraphNcurses()
{
    if (!initscr())
        throw Exception("LibGraphNcurses: could not initiate window");
    cbreak();
    noecho();
    nonl();
    nodelay(stdscr, true);
    intrflush(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
}

LibGraphNcurses::~LibGraphNcurses()
{
    endwin();
}

void LibGraphNcurses::getKeyboardEvents(std::vector<KeyState> &keysGame, std::vector<KeyState> &keysCore)
{
    Key current;

    for (int key = getch(); key != NO_KEY; key = getch()) {
        if (NCURSES_KEYMAP.find(key) == NCURSES_KEYMAP.end())
            continue;
        current = NCURSES_KEYMAP.at(key);
        for (auto &it : keysGame) {
            if (it.key == current) {
                it.is_pressed = true;
                break;
            }
        }
        for (auto &it : keysCore) {
            if (it.key == current) {
                it.is_pressed = true;
                break;
            }
        }
    }
}

void LibGraphNcurses::displayImage(int id, size_t posX, size_t posY)
{
    displayImage(id, static_cast<double>(posX), static_cast<double>(posY));
}

void LibGraphNcurses::displayImage(int id, double posX, double posY)
{
    try {
        Image &img = _images.at(id);
        img.posX = posX;
        img.posY = posY;
    } catch (...) {
        throw Exception("displayImage: incorrect id:" + std::to_string(id));
    }
}

void LibGraphNcurses::displayText(int fontID, size_t posX, size_t posY, std::string const &text)
{
    int x = getcurx(stdscr);
    int y = getcury(stdscr);

    mvaddstr(posY, posX, text.c_str());
    move(y, x);
}

void LibGraphNcurses::clear()
{
    erase();
}

void LibGraphNcurses::render()
{
    refresh();
}

void LibGraphNcurses::loadResourceImage(int id, std::string const &filepathGraph, std::string const &filepathAscii)
{
    std::ifstream file(filepathAscii);
    std::stringstream buffer;

    if (!file.good())
        throw LibGraphNcurses::Exception("loadResourceImage: error opening file:" + filepathAscii);
    buffer << file.rdbuf();
    _images[id] = Image(buffer.str());
}

void LibGraphNcurses::resetResource()
{
    _images.clear();
}
