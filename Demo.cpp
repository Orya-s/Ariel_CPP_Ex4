#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


void take_four_blue_cards(Player& player);
void take_four_different_color_cards(Player& player);
bool has_station(Board& board, City city);
void take_four_red_cards(Player& player);
void take_four_black_cards(Player& player);


int main()
{
	Board board;
	cout << "Is the board clean? " << boolalpha << board.is_clean() << "  -->  should print: true" << endl;
	board[City::Madrid] = 3;        // 3 blue cubes 
	board[City::SanFrancisco] = 2;  // 2 blue cubes 
	board[City::MexicoCity] = 1;    // 1 yellow cube 
	board[City::HoChiMinhCity] = 1; // 1 red cube 
	board[City::Chicago] = 4;       // 4 blue cubes
	cout << "Is the board clean? " << boolalpha << board.is_clean() << "  -->  should print: false" << endl;


	// checking OperationsExpert
	OperationsExpert player {board, City::Madrid}; 		
	take_four_different_color_cards(player);
	cout << "role: " << player.role() << "  -->  should print: OperationsExpert" << endl;
	player.build();	 // player is in Madrid - doesn't throw the card
	cout << "Madrid station: " << boolalpha << has_station(board, player.get_location()) 
		<< "  -->  should print: true" << endl;

	player.fly_charter(City::SanFrancisco);   // still have Madrid's card - so can fly charter
	player.build();	  // build a station in SF without the card	
	cout << "SanFrancisco station: " << boolalpha << has_station(board, player.get_location()) 
		<< "  -->  should print: true" << endl;		


	// checking Dispatcher
	Dispatcher player2 {board, City::London}; 		
	take_four_blue_cards(player2);
	cout << "role: " << player2.role() << "  -->  should print: Dispatcher" << endl;
	player2.build();	// has the card for London
	cout << "London station: " << boolalpha << has_station(board, player2.get_location()) 
		<< "  -->  should print: true" << endl;
	
	player2.fly_direct(City::Madrid);	// doesn't have the card - there's a station
	player2.take_card(City::London);	// now has 4 blue cards
	try
	{
		player2.discover_cure(Color::Blue);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// doesn't have 5 blue cards
	}

	player2.take_card(City::Washington);
	player2.discover_cure(Color::Blue);
	cout << "Is there Blue cure: " << boolalpha << board.is_cured(Color::Blue)
		<< "  -->  should print: true" << endl;
	

	// checking Scientist
	Scientist player3 {board, City::Tokyo, 4}; 
	take_four_red_cards(player3);
	cout << "role: " << player3.role() << "  -->  should print: Scientist" << endl;
	player3.fly_charter(SanFrancisco);	// has a station
	try
	{
		player3.discover_cure(Color::Red);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// doesn't have 4 red cards
	}

	player3.take_card(Tokyo);
	player3.discover_cure(Color::Red);	// now has 4 red cards
	cout << "Is there Red cure: " << boolalpha << board.is_cured(Color::Red)
		<< "  -->  should print: true" << endl;


	// checking Researcher
	Researcher player4 {board, City::Algiers}; 		
	take_four_black_cards(player4);
	cout << "role: " << player4.role() << "  -->  should print: Researcher" << endl;
	player4.take_card(Tehran);	// now has 5 black cards
	player4.discover_cure(Color::Black);	// doesn't need a station!
	cout << "Is there Black cure: " << boolalpha << board.is_cured(Color::Black)
		<< "  -->  should print: true" << endl;

	player4.drive(City::Paris);
	try
	{
		player4.fly_direct(City::BuenosAires);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// doesn't have the city's card
	}


	// adding more disease cubes
	board[City::LosAngeles] = 3;     // 3 yellow cubes 
	board[City::Milan] = 2;         // 2 blue cubes 
	board[City::Taipei] = 1;       // 1 red cube 
	board[City::Riyadh] = 1;      // 1 black cube 
	board[City::Osaka] = 4;      // 4 red cubes 


	// checking Medic
	Medic player5 {board, City::LosAngeles}; 		
	take_four_different_color_cards(player5);
	cout << "role: " << player5.role() << "  -->  should print: Medic" << endl;
	player5.treat(City::LosAngeles);	// takes out all cubes
	cout << "Number of disease cubes in LA: " << board[City::LosAngeles] << "  -->  should print: 0" << endl;
	
	player5.fly_direct(City::Madrid);	// there's a Blue cure - eareses all cubes from the city
	cout << "Number of disease cubes in Madrid: " << board[City::Madrid] << "  -->  should print: 0" << endl;
	player5.take_card(City::Paris).drive(City::Paris).build();	// building a staion in Paris
	player5.fly_shuttle(City::SanFrancisco);	// there's a staion in both cities


	// checking Virologist
	Virologist player6 {board, City::LosAngeles}; 		
	take_four_different_color_cards(player6);
	cout << "role: " << player6.role() << "  -->  should print: Virologist" << endl;
	player6.treat(City::Osaka);   // doesn't need to be in the city , alreay have Red cure 
	cout << "Number of disease cubes in Osaka: " << board[City::Osaka] << "  -->  should print: 0" << endl;

	try
	{
		player6.treat(City::LosAngeles);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// La doesn't have any cubes
	}
	

	// checking GeneSplicer
	GeneSplicer player7 {board, City::MexicoCity};		
	take_four_different_color_cards(player7);
	cout << "role: " << player7.role() << "  -->  should print: GeneSplicer" << endl;
	player7.take_card(City::MexicoCity).build(); 
	try
	{
		player7.discover_cure(Color::Yellow);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// doesn't have enough cards
	}

	player7.take_card(City::Johannesburg);
	cout << "Is there Yellow cure: " << boolalpha << board.is_cured(Color::Yellow)
		<< "  -->  should print: false" << endl;
	player7.discover_cure(Color::Yellow);   // doesn't need all of the cards to be in the same color
	cout << "Is there Yellow cure: " << boolalpha << board.is_cured(Color::Yellow)
		<< "  -->  should print: true" << endl;


	// checking FieldDoctor
	FieldDoctor player8 {board, City::Essen}; 		
	take_four_black_cards(player8);
	cout << "role: " << player8.role() << "  -->  should print: FieldDoctor" << endl;
	try
	{
		player8.treat(City::StPetersburg);
	}
	catch(const exception& e)
	{
		cerr << "   caught exception: " << e.what() << endl;	// StPetersburg doesn't have any cubes
	}

	player8.treat(City::Milan);	  // doesn't need to be there or throw the card
	cout << "Number of disease cubes in Milan: " << board[City::Milan] << "  -->  should print: 0" << endl;
	player8.drive(City::Paris).drive(City::Algiers).drive(City::Cairo);
	player8.fly_charter(City::MexicoCity).drive(City::Lima);



	cout << "\n" << board << endl; // printing the board

	return 0;
}



void take_four_blue_cards(Player& player) {
	player.take_card(City::Atlanta)
	      .take_card(City::SanFrancisco)
	      .take_card(City::NewYork)
	      .take_card(City::London);
}

void take_four_different_color_cards(Player& player) {
	player.take_card(City::LosAngeles) // yellow
	      .take_card(City::Cairo)      // black  
	      .take_card(City::Osaka)      // red
	      .take_card(City::Madrid);    // blue
}

bool has_station(Board& board, City city) {
	return board.cities.at(city).has_station();
}

void take_four_red_cards(Player& player) {
	player.take_card(City::Seoul)
	      .take_card(City::Tokyo)
	      .take_card(City::HongKong)
	      .take_card(City::Bangkok);
}

void take_four_black_cards(Player& player) {
	player.take_card(City::Mumbai)
	      .take_card(City::Cairo)
	      .take_card(City::Istanbul)
	      .take_card(City::Delhi);
}
