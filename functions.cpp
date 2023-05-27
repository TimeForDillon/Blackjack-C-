#include "header.h"

/*******************************************************************************
 * FUNCTION startPlayerDraw
 * _____________________________________________________________________________
 *  This function starts the game by dealing out two cards to the player.
 *  - returns nothing outputs two card for player.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      &cardName   : String name of card.
 *      &playerScore: Player's hand value.
 *
 * POST-CONDITIONS
 *      passes &playerScore and &cardName by reference and outputs them.
 ******************************************************************************/

void startPlayerDraw(string &cardName, // IN - string name of card
                     int &playerScore) // IN - player's hand value

{
    // OUTPUT - player's cards and initial total
    cout << "Your cards are: \n";
    // PROCESSING - deal twice
    for(int i=0;i<2;i++)
    {
        // draw_card - draws card to player
        playerScore += draw_card(cardName,playerScore);
        cout << cardName << endl;
    }
    cout << "Your total is " << playerScore << ". ";
}

/*******************************************************************************
 * FUNCTION startDealerDraw
 * _____________________________________________________________________________
 * This function starts dealers hand by dealing out two cards to the dealer.
 *  - returns nothing ouputs two cards for dealer.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      &cardName   : String name of card.
 *      &dealerScore: Dealer's hand value.
 *
 * POST-CONDITIONS
 *      passes &dealerScore and &cardName by reference and outputs them.
 ******************************************************************************/

void startDealerDraw(string &cardName, // IN - string name of card
                     int &dealerScore) // IN - dealer's hand value
{
    // OUTPUT - dealer's cards and initial total.
    cout << "The dealer's cards are: \n";
    // PROCESSING - deal twice
    for(int i=0;i<2;i++)
    {
        // draw_card - draws card to dealer
        dealerScore += draw_card(cardName,dealerScore);
        cout << cardName << endl;
    }
    cout << "The dealer's total is " << dealerScore << ".\n";
}

/*******************************************************************************
 * FUNCTION getRank
 * _____________________________________________________________________________
 * This function takes in the numerical card rank value and converts it to
 *  a string with the cards value name. (jack, queen, king, ace, etc.)
 *  - returns a string holding rank name.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      cardValue: Numeric value of card name.
 *
 * POST-CONDITIONS
 *      Returns string.
 ******************************************************************************/

string getRank(int cardValue)   // IN - numeric card value
{
    // PROCESSING - converts numerical value to string
    switch(cardValue)
    {
    default: return "Error";
    case 1: return "Ace";
    case 2: return "Two";
    case 3: return "Three";
    case 4: return "Four";
    case 5: return "Five";
    case 6: return "Six";
    case 7: return "Seven";
    case 8: return "Eight";
    case 9: return "Nine";
    case 10: return "Ten";
    case 11: return "Jack";
    case 12: return "Queen";
    case 13: return "King";
    }
}

/*******************************************************************************
 * FUNCTION getSuit
 * _____________________________________________________________________________
 * This function takes in the numerical card suit value and converts it to
 *  a string with the cards suit name. (diamonds, hearts, etc.)
 *  - returns a string holding suit name.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      cardSuit: Numeric value of suit name.
 *
 * POST-CONDITIONS
 *      Returns string.
 ******************************************************************************/

string getSuit(int cardSuit)    // IN - numeric suit value
{
    // PROCESSING - converting nuerical value to string
    switch(cardSuit)
    {
    default: return "Error";
    case 1: return "Spades";
    case 2: return "Clubs";
    case 3: return "Diamonds";
    case 4: return "Hearts";
    }
}

/*******************************************************************************
 * FUNCTION draw_card
 * _____________________________________________________________________________
 * Simulates the drawing of a card. Passes by reference the kind of card (value
 *  and suite in string value) as well as returns the card's equivalent
 *  numerical value (to be added to totals in main()). Also reads current
 *  drawer's points to determine value of aces.
 *  - returns int value of card.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      &cardName     : Passes card info.
 *      &drawer_points: Reads current drawer's points to determine value of ace.
 *
 * POST-CONDITIONS
 *      Passes card info by reference, returns card numerical value.
 ******************************************************************************/

int draw_card(string &cardName,     // IN - string name of card
              int drawer_points)    // IN - player or dealer hand value
{
    int cardValue;             // CALC - holds the rand number for card value
    int cardSuit;              // CALC - holds the rand number for suit
    string cardValueName;      // CALC - holds the cards value text name
    string cardSuitName;       // CALC - holds the cards suit text name

    // PROCESSING - random numbers
    cardValue = rand() % 13 + 1;
    cardSuit = rand() % 4 + 1;
    // getRank - converts card value number to card name
    cardValueName = getRank(cardValue);
    // getSuit - converts suit value number to suit name
    cardSuitName = getSuit(cardSuit);
    cardName = "  " + cardValueName + " of " + cardSuitName;
    // PROCESSING - determining value of ace based on hand value
    if(cardValue == 1 && drawer_points > 10) return 1;
    else if(cardValue == 1 && (drawer_points <= 10)) return 11;
    else if(cardValue >= 10)
    {
        return 10;
    }
    else return cardValue;
}
