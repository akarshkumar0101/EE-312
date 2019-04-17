//card.cpp
#include "card.h"

Card::Card(){
    this->mySuit = Card::Suit::spades;
	this->myRank = 1;
}          // default, ace of spades

Card::Card(int rank, Suit s){
	this->mySuit = s;
	this->myRank = rank;
}

string Card::toString()              const{
	return rankString(this->myRank)+suitString(this->mySuit);
}  // return string version e.g. Ac 4h Js
bool Card::sameSuitAs(const Card& c) const{
	return this->mySuit == c.mySuit;
}  // true if suit same as c
int  Card::getRank()                 const{
	return this->myRank;
} // return rank, 1..13
string Card::suitString(Suit s)      const {
    if(s==Card::Suit::spades){
		return "s";
	}
    else if(s==Card::Suit::hearts){
		return "h";
	}
    else if(s==Card::Suit::diamonds){
		return "d";
	}
    else if(s==Card::Suit::clubs){
        return "c";
	}
	return "";
}  // return "s", "h",...

string Card::rankString(int r)       const{
	if(r==ACE){
		return "A";
	}
	else if(r==JACK){
		return "J";
	}
	else if(r==QUEEN){
		return "Q";
	}
	else if(r==KING){
		return "K";
	}
	else{
        char c = '0';
        c+=r;
		return string(1, c);
	}
}  // return "A", "2", ..."Q"  


bool Card::operator == (const Card& rhs) const{
	return this->myRank==rhs.myRank && this->mySuit ==rhs.mySuit;
}
bool Card::operator != (const Card& rhs) const{
	return !(*this==rhs);
}

ostream& operator << (ostream& out, const Card& c){
	return cout << c.toString();
}

