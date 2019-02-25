#include <iostream>
#include <iomanip>
#include <string>


/**********************
 ** GLOBAL VARIABLES **
 **********************/
	const int SUIT_MAX = 4;
const int FACE_MAX = 13;


/**********************
 **    CARD CLASS    **
 **********************/
class Card {
public:

	// SUIT DEFINITIONS
	const int NUM_CLUBS = 1;
	const int NUM_HEARTS = 2;
	const int NUM_SPADES = 3;
	const int NUM_DIAMONDS = 4;

	std::string STR_CLUBS = "Clubs";
	std::string STR_HEARTS = "Hearts";
	std::string STR_SPADES = "Spades";
	std::string STR_DIAMONDS = "Diamonds";

	const int NUM_ACE = 1;
	const int NUM_JACK = 11;
	const int NUM_QUEEN = 12;
	const int NUM_KING = 13;

	std::string STR_ACE = "Ace";
	std::string STR_JACK = "Jack";
	std::string STR_QUEEN = "Queen";
	std::string STR_KING = "King";

	// Determine a random suit to which the card belongs.
	std::string determineSuit() {
		int suitChoice = ((rand() % SUIT_MAX) + 1);
		if (suitChoice == NUM_CLUBS) {
			return STR_CLUBS;
		}
		else if (suitChoice == NUM_HEARTS) {
			return STR_HEARTS;
		}
		else if (suitChoice == NUM_SPADES) {
			return STR_SPADES;
		}
		else
			return STR_DIAMONDS;
	}

	// Determine a random vace value.
	int determineFace() {
		int faceChoice = ((rand() % FACE_MAX) + 1);
		return faceChoice;
	}

	// Change the value of the face to the name of the face for output.
	std::string faceName(int faceChoice) {
		switch (faceChoice) {
		case 1: return STR_ACE;
			break;
		case 2:  return "Two";
			break;
		case 3: return "Three";
			break;
		case 4: return "Four";
			break;
		case 5: return "Five";
			break;
		case 6: return "Six";
			break;
		case 7: return "Seven";
			break;
		case 8: return "Eight";
			break;
		case 9: return "Nine";
			break;
		case 10: return "Ten";
			break;
		case 11: return STR_JACK;
			break;
		case 12: return STR_QUEEN;
			break;
		case 13: return STR_KING;
			break;
		default: return " ";

		}
	}

	// Generate the card's suit.
	std::string getCardSuit() {
		std::string suit = determineSuit();
		return suit;
	}

	// Generate the card's face.
	std::string getCardFace(int faceValue) {
		std::string faceResult = faceName(faceValue);
		return faceResult;
	}

	// Draw a card.
	void drawCard() {

		//determine the face value of the card and the length in characters.
		int faceValue = determineFace();
		std::string cardFace = getCardFace(faceValue);
		int faceLength = cardFace.length();

		//determine the face of the card and the length of the face text in characters.
		std::string cardSuit = getCardSuit();
		int cardSuitLength = cardSuit.length();

		//print the card on screen
		std::cout << std::setfill('*') << std::setw(10) << "*" << std::endl;
		std::cout << "*" << cardFace << std::setw(9 - faceLength) << std::setfill(' ') << "*" << std::endl;
		std::cout << "*        *" << std::endl;
		std::cout << "*   of   *" << std::endl;
		std::cout << "*        *" << std::endl;
		std::cout << "*" << std::setw(8) << std::setfill(' ') << cardSuit << "*" << std::endl;
		std::cout << std::setfill('*') << std::setw(10) << "*" << std::endl << "\r";
	}

private:
	//Nothing yet.//

};


/**********************
 **       MAIN       **
 **********************/
int main() {

	// Initialize Random Seed
	unsigned int seed = time(0);
	srand(seed);

	// Begin
	int verifier = 0;
	std::cout << "Welcome to the world's most advance and futuristic card drawing simulator." << std::endl;
	std::cout << "Would you like to draw a card?" << std::endl;
	std::cout << "Press 1 for Yes. Enter any other choice for No." << std::endl;
	std::cin >> verifier;

	// Loop
	while (verifier == 1) {
		Card card_1;
		Card card_2;

		card_1.drawCard();
		card_2.drawCard();

		std::cout << "Draw again?" << std::endl;
		std::cout << "Press 1 for Yes. Enter any other choice for No.'" << std::endl;
		std::cin >> verifier;
	}

	// End
	std::cout << "Bye!" << std::endl;
	return 0;
}
