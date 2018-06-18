#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game_control.h"


void Game::start_menu()
{
    std::string banner = R"x(
    ####  ####  ####  #  #   ####  ####  ####  ####  ####
    #  #  #  #  #     # #    #  #  #  #  #  #  #     #  #
    ####  #  #  #     ##     ####  ####  ####  ####  ####
    # #   #  #  #     # #    #     #  #  #     #     # #
    #  #  ####  ####  #  #   #     #  #  #     ####  #  #


       ####  ####  #  ####  ####  ####  ####
       #     #     #  #     #     #  #  #  #
       ####  #     #  ####  ####  #  #  ####
          #  #     #     #     #  #  #  # #
       ####  ####  #  ####  ####  ####  #  #

    )x";

    std::cout << banner;

    unsigned int selection;
    show_menu:
    std::cout << "\tPress\n";
    std::cout << "\t1 to Enter\n";
    std::cout << "\t2 to Exit\n";
    std::cin >> selection;

    std::cin.clear();
    std::cin.ignore();

    switch(selection)
    {
        case 1: start_game();
                break;
        case 2: exit_game();
                break;
        default: std::cout << "-------Enter valid choice--------\n";
                 goto show_menu;
                 break;
    }
}

void Game::exit_game()
{
    std::cout << "Thanks for playing!!\n";
    exit(EXIT_SUCCESS);
}

void Game::start_game()
{

    std::cout << "\nEnter your name\n";
    std::getline(std::cin, user_name);
    std::cout << "Enter number of turns for you want to play\n";
    std::cin >> number_of_turns;

    while (number_of_turns--)
    {
        unsigned int user_choice, comp_choice;
        std::cout << "\nEnter your choice\n";
        show_choices:
        std::cout << "\nPress\n";
        std::cout << "1 for ROCK\t2 for PAPER\t3 for SCISSOR\n";
        std::cin >> user_choice;
        if (user_choice > 3)
        {
            std::cout << "\n---------Please enter valid choice------------\n";
            goto show_choices;
        }
        user_choice--;

        srand(time(0));
        comp_choice = rand() % 3;

        game_play(user_choice, comp_choice);
        std::cout << "The score is\t";
        std::cout << user_name << " = " << user_score;
        std::cout << "\tComputer = " << comp_score << "\n";
    }
    exit_game();
}

void Game::game_play(unsigned int user_choice, unsigned int comp_choice)
{
    if (user_choice != comp_choice)
    {
        std::cout << user_name << " chooses " << choices[user_choice];
        std::cout << " and Computer chooses " << choices[comp_choice] << "\n";

        if ( (user_choice % 3) == ((comp_choice+1) % 3) )
        {
            std::cout << "----" << user_name << " Wins!!----\n";
            user_score++;
        }
        else
        {
            std::cout << "----Computer Wins!!----\n";
            comp_score++;
        }
    }
    else
    {
        std::cout << "Both " << user_name << " and Computer chooses " << choices[user_choice];
        std::cout << "\n";
    }
}
