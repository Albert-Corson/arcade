/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibGraphNcurses
*/

#pragma once

#include "ALibGraph.hpp"
#include "init_graph_lib.hpp"
#include <ncurses.h>
#include <unordered_map>

namespace arcade {
    class LibGraphNcurses: public ALibGraph {
        public:
            LibGraphNcurses();
            ~LibGraphNcurses() override;

            void getKeyboardEvents(std::vector<KeyState> &keysGame, std::vector<KeyState> &keysCore) override final;
            void displayImage(int id, int posX, int posY) override final;
            void displayImage(int id, double posX, double posY) override final;
            void displayText(int fontID, int posX, int posY, std::string const &text) override final;
            void playAudio(int id, bool repeat = false) override final {};
            void stopAudio(int id) override final {};
            void clear() override final;
            void render() override final;
            void loadResourceAudio(int id, std::string const &filepath) override final {};
            void loadResourceFont(int id, std::string const &filepath) override final {};
            void loadResourceImage(int id, std::string const &filepathGraph, std::string const &filepathAscii) override final;
            void resetResource() override final;

        private:
            std::unordered_map<int, std::string> _images;
    };
}
