//
//  player.cpp
//  Assignment 6 - Go Fish
//
//  Created by Akarsh Kumar on 4/8/19.
//  Copyright © 2019 Akarsh Kumar. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <algorithm>


#include "player.h"


void Player::addCard(Card c){
    myHand.push_back(c);
}  //adds a card to the hand
void Player::bookCards(Card c1, Card c2){
    auto itr1 = find(myHand.begin(),myHand.end(),c1);
    auto itr2 = find(myHand.begin(),myHand.end(),c2);
    if(itr1 != myHand.end() && itr2 != myHand.end()){
        myHand.erase(itr1);
        auto itr2 = find(myHand.begin(),myHand.end(),c2);
        myHand.erase(itr2);
        myBook.push_back(c1);
    }
}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    int i = rand() % myHand.size();
    return myHand[i];
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    auto itr = find(myHand.begin(), myHand.end(),c);
    return itr!=myHand.end();
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    auto itr = find(myHand.begin(), myHand.end(),c);
    if(itr!=myHand.end()){
        myHand.erase(itr);
        return c;
    }
    else{
        return Card();
    }
}

string Player::showHand() const{
    string str = "";
    for(auto itr = myHand.begin();itr != myHand.end();itr++){
        str+= itr->toString() +" ";
    }
    return str;
}
string Player::showBooks() const{
    string str = "";
    for(auto itr = myBook.begin();itr != myBook.end();itr++){
        str+= itr->toString() +" ";
    }
    return str;
}

int Player::getHandSize() const{
    return (int) myHand.size();
}
int Player::getBookSize() const{
    return (int) myBook.size();
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){
    for(auto itr = myHand.begin();itr != myHand.end();itr++){
        for(auto itr2 = myHand.begin();itr2 != myHand.end();itr2++){
            if(itr->getRank() == itr2->getRank() && (*itr) != (*itr2)){
                c1 = *itr;
                c2 = *itr2;
                return true;
            }
        }
    }
    return false;
}

bool Player::hasSameRankInHand(Card& c) const{
    for(auto itr = myHand.begin();itr != myHand.end();itr++){
        if(itr->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

Card Player::sameRankInHand(Card& c) const{
    for(auto itr = myHand.begin();itr != myHand.end();itr++){
        if(itr->getRank() == c.getRank()){
            return *itr;
        }
    }
    return Card();
}
