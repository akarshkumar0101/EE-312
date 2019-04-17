// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <ctime>
#include "card.h"
#include "player.h"
#include "deck.h"


using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void checkAndBookCards(Player &p, Player &p2);

void printHand(Player &p);
void printBook(Player &p);

const string fileName = "gofish_results.txt";
ofstream out;
int main()
{
    
    out.open(fileName);
    
    srand((unsigned)time(0)); 
    int numCards = 7;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    
    out<<"Dealing cards to players"<<endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    
    out<<"Done dealing cards, these are what they drew: "<<endl;
    
    printHand(p1);
    printHand(p2);
    
    out<<endl;
    
    Player* currentPlayer = &p1;
    Player* otherPlayer = &p2;
    
    
    bool switchTurns = false;
    do {
        out<<"-------------------------------------------"<<endl;
        out<<currentPlayer->getName()<<"'s Turn";
        if(!switchTurns){
            out<<" (Again)";
        }
        out<<endl;
        out<<"-------------------------------------------"<<endl;
        
        checkAndBookCards(*currentPlayer, *otherPlayer);
        
        out<<endl;
        printHand(p1);
        printHand(p2);
        out<<"Deck size: "<<d.size()<<endl;
        out<<endl;
        
        
        switchTurns = false;
        
        
        if(currentPlayer->getHandSize()==0){
            if(d.size()!=0){
                currentPlayer->addCard(d.dealCard());
            }
            switchTurns = true;
        }
        else{
            Card c = currentPlayer->chooseCardFromHand();
            //Jane asks - Do you have a 6?
            out<<currentPlayer->getName()<<" asks - Do you have a "<< c.rankString(c.getRank()) <<"?" << " (Referring to his "<<c.toString()<<")"<<endl;
            //Joe says - Go Fish
            //Joe says - Yes. I have a 4.
            out<<otherPlayer->getName()<< " says - ";
            if(otherPlayer->hasSameRankInHand(c)){
                
                Card t = otherPlayer->sameRankInHand(c);
                out<<"Yes. I have a "<< c.rankString(c.getRank()) << " (Referring to his "<<t.toString()<<")"<<endl;
                
                otherPlayer->removeCardFromHand(t);
                currentPlayer->addCard(t);
                
                out<<"Transferred "<<t.toString()<<endl;
                switchTurns = false;
            }
            else{
                out<<"Go Fish"<<endl;
                Card card = d.dealCard();
                currentPlayer->addCard(card);
                
                //Joe draws 4d
                out<<currentPlayer->getName()<< " draws "<<card.toString() << endl;
                
                switchTurns = true;
            }
            
        }
        
        if(switchTurns){
            Player* temp = currentPlayer;
            currentPlayer = otherPlayer;
            otherPlayer = temp;
        }
        
    } while(currentPlayer->getBookSize()+otherPlayer->getBookSize()<26);
    
    out<<"-------------------------------------------"<<endl;
    out<<"Game Over! "<<endl;
    
    printBook(p1);
    printBook(p2);
    
    
    Player* winner = &p1;
    if(p2.getBookSize()>p1.getBookSize()){
        winner = &p2;
    }
    if(p2.getBookSize()==p1.getBookSize()){
        winner = NULL;
    }
    out<<endl;
    out<<"*****";
    if(winner!=NULL){
        out<<winner->getName()<<" wins!";
    }
    else{
        out<<"There is a draw between "<<p1.getName()<<" and "<<p2.getName();
    }
    out<<"*****"<<endl;
       
    
    out.close();
    return EXIT_SUCCESS;  
}

void checkAndBookCards(Player &p, Player &p2){
    Card c1, c2;
    if(p.checkHandForPair(c1, c2)){
        p.bookCards(c1, c2);
        out<< p.getName() << " books " << c1.toString()<<" and " << c2.toString()<< endl;
    }
    if(p2.checkHandForPair(c1, c2)){
        p2.bookCards(c1, c2);
        out<< p2.getName() << " books " << c1.toString()<<" and " << c2.toString()<< endl;
    }
}


void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}


void printHand(Player &p){
    out<< p.getName() <<"'s Hand:"<<endl;
    out<< p.showHand() <<endl;
}
void printBook(Player &p){
    out<< p.getName() <<"'s Book:"<<endl;
    out<< p.showBooks() <<endl;
}
