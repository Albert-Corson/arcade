/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ILibGraph
*/

#pragma once

#include "deps/keys.hpp"
#include <memory>
#include <vector>

namespace arcade {
    constexpr auto cell_size_x = 15;
    constexpr auto cell_size_y = 15;

    class ILibGraph {
        public:
            virtual ~ILibGraph() = default;

            // Returns the keyboard events
            virtual void getKeyboardEvents(std::vector<KeyState> &keysGame, std::vector<KeyState> &keysCore) = 0;

            // Draws an image at a given position
            virtual void displayImage(int id, int posX, int posY) = 0;
            virtual void displayImage(int id, double posX, double posY) = 0;

            // Draws text at a given position
            virtual void displayText(int id, int posX, int posY, std::string const &text) = 0;

            // Plays an audio resource
            virtual void playAudio(int id, bool repeat = false) = 0;

            // Stops playing an audio resource
            virtual void stopAudio(int id) = 0;

            // Clears the window
            virtual void clear() = 0;

            // Renders the window
            virtual void render() = 0;

            // Loads a new sound
            // Throws an exception in case of failure
            virtual void loadResourceAudio(int id, std::string const &filepath) = 0;

            // Loads a new font
            // Throws an exception in case of failure
            virtual void loadResourceFont(int id, std::string const &filepath) = 0;

            // Loads a new image
            // Throws an exception in case of failure
            virtual void loadResourceImage(int id, std::string const &filepathGraph, std::string const &filepathAscii) = 0;

            // erases all content of resources
            virtual void resetResource() = 0;
    };
}
