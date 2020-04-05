/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#pragma once

#include <unordered_map>
#include <fstream>
#include "AGame.hpp"

namespace arcade {
    typedef struct
    {
        int x;
        int y;
        char val;
    }pos_t;

    class Game : public AGame {
        public:
            typedef void (Game::*keyAction_t)(Key);

            Game(ICore &core);
            ~Game() override = default;

            void launch() override final;

        private:
            void processKeys(int &map, double &idx);
            void pause(Key key = Key::UNKNOWN);
            void resetGame();
            void changeMap(int &map, double &idx);
            void initAssets();
            void displayKeys(const int x, const int map);
            void displayAssets(double idx);
            Key snakeDirection(size_t i);
            bool canMove();
            void sceneGame(std::unique_ptr<IClock> &cl, double &idx, int &map);
            void gameMotor();
            Key onlyOneKey();
            void initMap(void);
            void initSnake(const char id);
            int getPos(int x, int y);
            std::vector<pos_t> getMap();
            void moveSnake(const int x, const int y, const Key key);
            void moveDown(Key key = Key::UNKNOWN);
            void moveUp(Key key = Key::UNKNOWN);
            void moveRight(Key key = Key::UNKNOWN);
            void moveLeft(Key key = Key::UNKNOWN);
            void moveTail(void);
            void eatFruit(void);
            void checkFruit(void);

            int _gameState;
            std::vector<KeyState> _actionKeys;
            std::unordered_map<Key, keyAction_t> _keyActions;
            std::vector<pos_t> _map;
            std::vector<pos_t> _snake;
            Key _lastKey;
            int _currentMap;
    };
}
