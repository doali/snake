#ifndef _TIMER_HPP
#define _TIMER_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <chrono>
#include <ctime>
#include <iostream>

namespace timer
{
    static void info_time_sec()
    {
        std::time_t result = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&result))
                  << result << " seconds since the Epoch\n";
    }

    struct Timer
    {
        explicit Timer(sf::RenderWindow &p_window, unsigned int p_milli) : _window(p_window), _milli(p_milli) {}
        ~Timer() = default;

        void add(std::function<void(sf::RenderWindow &)> p_callback, sf::RenderWindow &p_window)
        {
            _callback = p_callback;
        }

        void start()
        {
            _start = std::chrono::high_resolution_clock::now();
        }

        void run()
        {
            auto l_now{std::chrono::high_resolution_clock::now()};
            auto elapsed{std::chrono::duration_cast<std::chrono::milliseconds>(l_now - _start)};

            if (elapsed.count() >= _milli)
            {
                _callback(_window);
                _start = l_now;
                // info_time_sec();
            }
        }

        sf::RenderWindow &_window;
        unsigned int _milli{0};
        std::function<void(sf::RenderWindow &)> _callback;
        std::chrono::high_resolution_clock::time_point _start;
    }; // namespace timer
}

#endif