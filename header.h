#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <ctime>

using namespace std;

/*******************************************************************************
 * startPlayerDraw
 * This function starts the game by dealing out two cards to the player.
 *  - returns nothing outputs two card for player
 ******************************************************************************/

void startPlayerDraw(string &cardName,  // IN - string name of card
                     int &playerScore); // IN - player's hand value

/*******************************************************************************
 * startDealerDraw
 * This function starts dealers hand by dealing out two cards to the dealer.
 *  - returns nothing ouputs two cards for dealer
 ******************************************************************************/

void startDealerDraw(string &cardName,  // IN - string name of card
                     int &dealerScore); // IN - dealer's hand value

/*******************************************************************************
 * getRank
 * This function takes in the numerical card rank value and converts it to
 *  a string with the cards value name. (jack, queen, king, ace, etc.)
 *  - returns a string holding rank name
 ******************************************************************************/

string getRank(int cardValue);  // IN - numeric card value

/*******************************************************************************
 * getSuit
 * This function takes in the numerical card suit value and converts it to
 *  a string with the cards suit name. (diamonds, hearts, etc.)
 *  - returns a string holding suit name
 ******************************************************************************/

string getSuit(int cardSuit);   // IN - numeric suit value

/*******************************************************************************
 * draw_card
 * This function produces one random number that represents the numerical
 *  face value of the playing card and another random number that reprsents
 *  the suit of the playing card.
 *  - returns int value of card
 ******************************************************************************/

int draw_card(string &cardName,   // IN - string name of card
              int drawer_points); // IN - player or dealer hand value

#endif // HEADER_H
