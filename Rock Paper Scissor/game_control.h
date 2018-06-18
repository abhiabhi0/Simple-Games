#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <iostream>
#include <array>
#include <string>

class Game
{
    unsigned int number_of_turns = 0;
    unsigned int user_score = 0, comp_score = 0;
    std::array<std::string, 3> choices = {{"ROCK", "PAPER", "SCISSOR"}};
    std::string user_name;

  public:
    Game()  = default;
    ~Game() = default;

    void start_menu();
    void start_game();
    void game_play(unsigned int, unsigned int);
    void exit_game();
};

#endif
