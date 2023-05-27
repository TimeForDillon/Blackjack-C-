/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * ASSIGNMENT 1  : BLACKJACK
 * CLASS         : CS3A
 * SECTION       : 71206
 * DUE DATE      : 9/2/2020
 ******************************************************************************/

#include "header.h"
#include "functions.cpp"

/*******************************************************************************
 * BLACKJACK
 * _____________________________________________________________________________
 * This program is a single-player version of the casino card game
 *  Blackjack, also known as 21. The goal of the game Blackjack is to get
 *  cards whose total value comes closest to 21 without going over. Getting
 *  a card total over 21 is called "busting". The player will play against
 *  the dealer. At each round of play, the player will be asked to enter
 *  their bet. They will then be given 2 cards. The player will repeatedly
 *  be asked if they want to draw another card. The player can continue to
 *  draw cards while their total is less than 21. After the player's turn
 *  is over, the dealer's cards are shown. The dealer's play is always the
 *  same: the dealer will continue to draw cards if their total is less
 *  than or equal to 16. Assume the player starts with $100 and the game
 *  ends when the player is down to $0 or their amount exceeds $1,000.
 * _____________________________________________________________________________
 * INPUT:
 *  int bet      : User input of bet ammount.
 *  string hit   : User input to determine whether to hit or stay.
 *  string replay: User input to determine whether to play again.
 *
 * OUTPUT:
 *  int bankRoll   : Player's avaliable funds.
 *  int playerScore: Player's current hand value.
 *  int dealerScore: Dealer's current hand value.
 *  string cardName: String storing current cards text name.
 ******************************************************************************/

int main()
{
    int bankRoll;           // CALC & OUT - stores players avaliable funds
    int playerScore;        // CALC & OUT - stores the players hand value
    int dealerScore;        // CALC & OUT - stores the dealers hand value
    int bet;                // IN - players bet
    string cardName;        // OUT - holds the txt name of the drawn card
    string hit;             // IN - user input to draw another card
    string replay;          // IN - user input to replay game

    bankRoll = 100;
    playerScore = 0;
    dealerScore = 0;
    srand(333);

    // PROCESSING - loop executed when user inputs response for replay at end
    do
    {
        // PROCESSING - loop executed when bet exceeds bankroll.
        do
        {
            // INPUT - user enters bet ammount
            cout << "You have $" << bankRoll << ". Enter bet: " << endl;
            cin >> bet;
        }while(bet > bankRoll);

        // startPlayerDraw - deals initial two cards to player
        startPlayerDraw(cardName,playerScore);
        cin.ignore();

        // PROCESSING - loop executed when user inputs response for hit and
        //              their hand value is less than or equal to 21
        do
        {
            // INPUT - user enters y/n for another card
            cout << "Do you want another card (y/n)? \n";
            getline(cin,hit);

            // PROCESSING - executes hit
            if(hit == "y")
            {
                // draw_card - deals card to player
                playerScore += draw_card(cardName,playerScore);
                // OUTPUT - player's hit
                cout << "You draw a: \n" << cardName << endl;
                cout << "Your total is " << playerScore << ". ";
            }
            else cout << endl << endl;
        }while((hit == "y") && (playerScore <= 21));

        // PROCESSING - if player doesn't bust start dealer's hand
        if(playerScore <= 21)
        {
            // startDealerDraw - deals initial two cards to dealer
            startDealerDraw(cardName,dealerScore);

            // PROCESSING - hits dealer's hand if below 17
            while (dealerScore <= 16)
            {
                // OUTPUT - dealer's hit
                cout << "The dealer draws a card.\n";
                // draw_card - deals card to dealer
                dealerScore += draw_card(cardName,dealerScore);
                cout << cardName << endl;

                // PROCESSING - dealer's bust
                if(dealerScore > 21)
                {
                    bankRoll += bet;
                    // OUTPUT - dealer's bust
                    cout << "The dealer's total is " << dealerScore << ".\n";
                    cout << "The dealer busted! You win $" << bet << ".\n\n";
                }
                // OUTPUT - dealer's total after hit
                else cout << "The dealer's total is " << dealerScore << ".\n";
            }

            // PROCESSING - player's win
            if((playerScore > dealerScore) && (playerScore <= 21))
            {
                bankRoll += bet;
                // OUTPUT - you win if players score is greater
                cout << "You win $" << bet << ".\n\n";
            }
            // PROCESSING - draw
            else if(playerScore == dealerScore)
            {
                // OUTPUT - draw if scores are equal
                cout << "Draw.\n\n";
            }
            // PROCESSING - dealer's win
            else if((playerScore < dealerScore) && (dealerScore <= 21))
            {
                bankRoll -= bet;
                // OUTPUT - you lose if dealers score is greater but not bust
                cout << "Too bad.  You lose $" << bet << ".\n\n";
            }
        }
        // PROCESSING - if player busts
        else
        {
            bankRoll -= bet;
            // OUTPUT - you busted if player hand is above 21
            cout << "You busted!\n\n";
        }

        dealerScore = 0;
        playerScore = 0;

        // PROCESSING - play again if bankroll is between $0 and $1000
        if((bankRoll > 0) && (bankRoll < 1000))
        {
            // INPUT - user enters y/n for another round
            cout << "Play again? (y/n): \n";
            getline(cin,replay);
        }
        // PROCESSING - game over
        else if(bankRoll <= 0)
        {
            // OUTPUT - game over once bankroll is below $0
            cout << "You have $" << bankRoll << ". GAME OVER.\n";
            break;
        }
        // PROCESSING - win
        else if(bankRoll >= 1000)
        {
            // OUTPUT - you win once bankroll is above $1000
            cout << "You have $" << bankRoll << ". YOU WIN!\n";
        }
    }while(replay == "y");

    return 0;
}
