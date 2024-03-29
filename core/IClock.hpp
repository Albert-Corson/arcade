/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** iclock
*/

#pragma once

namespace arcade {
    class IClock {
        public:
            virtual ~IClock() = default;

            virtual long getElapsedTime() = 0;
            virtual void reset() = 0;

        protected:
            IClock() = default;
    };
}
