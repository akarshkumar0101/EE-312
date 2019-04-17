//deck.cpp
#include "deck.h"
#include <cstdlib>
 
    
    
Deck::Deck(){
	int i = 0;

	for(int x=0; x<13;x++){
        Card card(x+1, Card::Suit::spades);
		myCards[i++] = card;
	}
	for(int x=0; x<13;x++){
        Card card(x+1, Card::Suit::hearts);
		myCards[i++] = card;
	}
	for(int x=0; x<13;x++){
        Card card(x+1, Card::Suit::diamonds);
		myCards[i++] = card;
	}
	for(int x=0; x<13;x++){
        Card card(x+1, Card::Suit::clubs);
		myCards[i++] = card;
	}

	myIndex = 51;
}           // pristine, sorted deck

void Deck::shuffle(){
	for(int i = 0; i < myIndex+1;i++){
    	int i2 = rand()%(myIndex+1);
    	Card tempCard = myCards[i];
    	myCards[i] = myCards[i2];
    	myCards[i2] = tempCard;
	}

}   // shuffle the cards in the current deck
Card Deck::dealCard(){
	if(myIndex == -1){
		//fail
        throw Card();
	}
	else{
		return myCards[myIndex--];
	}
}   // get a card, after 52 are dealt, fail 

int Deck::size() const{
	return myIndex+1;
} // # cards left in the deck
