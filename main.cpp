#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "header.h"
#include "functions.cpp"

int main()
{
    int bankRoll = 100;
    int playerScore = 0;
    int dealerScore = 0;
    int bet;
    std::string cardName;
    std::string hit;
    std::string replay;

    using namespace std;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    do
    {
        do
        {
            std::cout << "You have $" << bankRoll << ". Enter bet: ";
            std::cin >> bet;
        } while (bet > bankRoll);

        startPlayerDraw(cardName, playerScore);
        std::cin.ignore();

        // Variable to keep track of whether the player has doubled down
        bool doubledDown = false;

        if (playerScore == 21)
        {
            std::cout << "You already have 21!\n";
        }
        else
        {
            std::cout << "Do you want to double down? (y/n): ";
            std::getline(std::cin, hit);

            if (hit == "y")
            {
                if (bet * 2 > bankRoll)
                {
                    std::cout << "Insufficient funds to double down!\n";
                }
                else
                {
                    doubledDown = true;
                    bet *= 2;
                    playerScore += draw_card(cardName, playerScore);
                    std::cout << "You draw a:\n" << cardName << std::endl;
                    std::cout << "Your total is " << playerScore << ". ";
                }
            }
            else
            {
                do
                {
                    std::cout << "Do you want another card (y/n)? ";
                    std::getline(std::cin, hit);

                    if (hit == "y")
                    {
                        playerScore += draw_card(cardName, playerScore);
                        std::cout << "You draw a:\n" << cardName << std::endl;
                        std::cout << "Your total is " << playerScore << ". ";
                    }
                    else if (hit == "n")
                    {
                        std::cout << std::endl << std::endl;
                        break;
                    }
                } while (!doubledDown && (hit == "y") && (playerScore <= 21));
            }
        }

        if (playerScore <= 21)
        {
            startDealerDraw(cardName, dealerScore);

            while (dealerScore <= 16)
            {
                std::cout << "The dealer draws a card.\n";
                dealerScore += draw_card(cardName, dealerScore);
                std::cout << cardName << std::endl;

                if (dealerScore > 21)
                {
                    bankRoll += bet;
                    std::cout << "The dealer's total is " << dealerScore << ".\n";
                    std::cout << "The dealer busted! You win $" << bet << ".\n\n";
                }
                else
                {
                    std::cout << "The dealer's total is " << dealerScore << ".\n";
                }
            }

            if ((playerScore > dealerScore) && (playerScore <= 21))
            {
                bankRoll += bet;
                std::cout << "You win $" << bet << ".\n\n";
            }
            else if (playerScore == dealerScore)
            {
                std::cout << "Draw.\n\n";
            }
            else if ((playerScore < dealerScore) && (dealerScore <= 21))
            {
                bankRoll -= bet;
                std::cout << "Too bad. You lose $" << bet << ".\n\n";
            }
        }
        else
        {
            bankRoll -= bet;
            std::cout << "You busted!\n\n";
        }

        dealerScore = 0;
        playerScore = 0;

        if ((bankRoll > 0) && (bankRoll < 1000))
        {
            std::cout << "Play again? (y/n): ";
            std::getline(std::cin, replay);
        }
        else if (bankRoll <= 0)
        {
            std::cout << "You have $" << bankRoll << ". GAME OVER.\n";
            break;
        }
        else if (bankRoll >= 1000)
        {
            std::cout << "You have $" << bankRoll << ". YOU WIN!\n";
        }
    } while (replay == "y");

    return 0;
}
