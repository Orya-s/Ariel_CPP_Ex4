#include "Board.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {
   
    int& Board::operator[] (City city) 
    {
        return cities.at(city).get_cubes();
    }

    bool Board::is_clean() 
    {
        for (auto &i : cities)
        {
            if (i.second.get_cubes() != 0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures() 
    {
        found_cure.clear();
    }

    void Board::remove_stations()
    {
        for (auto &i : cities)
        {
            if (i.second.has_station())
            {
                i.second.remove_station();
            }
        }
    }

    void Board::add_cure(Color c)
    {
        found_cure.insert(c);
    }

    bool Board::is_cured(Color c) const
    {
        return count(found_cure.begin(), found_cure.end(), c) != 0;
    }


    std::ostream& operator<< (std::ostream& output, const Board& board)
    {
        output << "\n \033[1;31m *** Printing Board *** \033[0m \n";
        output << "Cures discoverd so far: ";
        for (const auto &i : board.found_cure)
        {
            if (i == Color::Black)
            {
                output << "\033[1;30mBlack \033[0m";
            }
            else if (i == Color::Blue)
            {
                output << "\033[1;34mBlue \033[0m";    
            }
            else if (i == Color::Red)
            {
                output << "\033[1;31mRed \033[0m"; 
            }
            else
            {
                output << "\033[1;33m Yellow \033[0m"; 
            }
            output << " ";
        }
        output << "\n" << endl;

        for (const auto &i : board.cities)
        {
            cout << i.second << endl;
        }

        return output;
    }



    void Board::init()
    {
        City_info Algiers(Color::Black, vector<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo}, "Algiers      ");
        cities.insert({City::Algiers, Algiers});

        City_info Atlanta(Color::Blue, vector<City>{City::Chicago, City::Miami, City::Washington}, "Atlanta      ");
        cities.insert({City::Atlanta, Atlanta});
        
        City_info Baghdad(Color::Black, vector<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}, "Baghdad      ");
        cities.insert({City::Baghdad, Baghdad});
    
        City_info Bangkok(Color::Red, vector<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}, "Bangkok      ");
        cities.insert({City::Bangkok, Bangkok});

        City_info Beijing(Color::Red, vector<City>{City::Shanghai, City::Seoul}, "Beijing      ");
        cities.insert({City::Beijing, Beijing});

        City_info Bogota(Color::Yellow, vector<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}, "Bogota       ");
        cities.insert({City::Bogota, Bogota});

        City_info BuenosAires(Color::Yellow, vector<City>{City::Bogota, City::SaoPaulo}, "BuenosAires  ");
        cities.insert({City::BuenosAires, BuenosAires});

        City_info Cairo(Color::Black, vector<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}, "Cairo        ");
        cities.insert({City::Cairo, Cairo});

        City_info Chennai(Color::Black, vector<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}, "Chennai      ");
        cities.insert({City::Chennai, Chennai});

        City_info Chicago(Color::Blue, vector<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}, "Chicago      ");
        cities.insert({City::Chicago, Chicago});

        City_info Delhi(Color::Black, vector<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}, "Delhi        ");
        cities.insert({City::Delhi, Delhi});

        City_info Essen(Color::Blue, vector<City>{City::London, City::Paris, City::Milan, City::StPetersburg}, "Essen        ");
        cities.insert({City::Essen, Essen});

        City_info HoChiMinhCity(Color::Red, vector<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}, "HoChiMinhCity");
        cities.insert({City::HoChiMinhCity, HoChiMinhCity});

        City_info HongKong(Color::Red, vector<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}, "HongKong     ");
        cities.insert({City::HongKong, HongKong});

        City_info Istanbul(Color::Black, vector<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}, "Istanbul     ");
        cities.insert({City::Istanbul, Istanbul});

        City_info Jakarta(Color::Red, vector<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}, "Jakarta      ");
        cities.insert({City::Jakarta, Jakarta});

        City_info Johannesburg(Color::Yellow, vector<City>{City::Kinshasa, City::Khartoum}, "Johannesburg ");
        cities.insert({City::Johannesburg, Johannesburg});

        City_info Karachi(Color::Black, vector<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}, "Karachi      ");
        cities.insert({City::Karachi, Karachi});

        City_info Khartoum(Color::Yellow, vector<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}, "Khartoum     ");
        cities.insert({City::Khartoum, Khartoum});

        City_info Kinshasa(Color::Yellow, vector<City>{City::Lagos, City::Khartoum, City::Johannesburg}, "Kinshasa     ");
        cities.insert({City::Kinshasa, Kinshasa});

        City_info Kolkata(Color::Black, vector<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}, "Kolkata      ");
        cities.insert({City::Kolkata, Kolkata});

        City_info Lagos(Color::Yellow, vector<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa}, "Lagos        ");
        cities.insert({City::Lagos, Lagos});

        City_info Lima(Color::Yellow, vector<City>{City::MexicoCity, City::Bogota, City::Santiago}, "Lima         ");
        cities.insert({City::Lima, Lima});

        City_info London(Color::Blue, vector<City>{City::NewYork, City::Madrid, City::Essen, City::Paris}, "London       ");
        cities.insert({City::London, London});

        City_info LosAngeles(Color::Yellow, vector<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}, "LosAngeles   ");
        cities.insert({City::LosAngeles, LosAngeles});

        City_info Madrid(Color::Blue, vector<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}, "Madrid       ");
        cities.insert({City::Madrid, Madrid});

        City_info Manila(Color::Red, vector<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong}, "Manila       ");
        cities.insert({City::Manila, Manila});

        City_info MexicoCity(Color::Yellow, vector<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}, "MexicoCity   ");
        cities.insert({City::MexicoCity, MexicoCity});

        City_info Miami(Color::Yellow, vector<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}, "Miami        ");
        cities.insert({City::Miami, Miami});

        City_info Milan(Color::Blue, vector<City>{City::Essen, City::Paris, City::Istanbul}, "Milan        ");
        cities.insert({City::Milan, Milan});

        City_info Montreal(Color::Blue, vector<City>{City::Chicago, City::Washington, City::NewYork}, "Montreal     ");
        cities.insert({City::Montreal, Montreal});

        City_info Moscow(Color::Black, vector<City>{City::StPetersburg, City::Istanbul, City::Tehran}, "Moscow       ");
        cities.insert({City::Moscow, Moscow});

        City_info Mumbai(Color::Black, vector<City>{City::Karachi, City::Delhi, City::Chennai}, "Mumbai       ");
        cities.insert({City::Mumbai, Mumbai});

        City_info NewYork(Color::Blue, vector<City>{City::Montreal, City::Washington, City::London, City::Madrid}, "NewYork      ");
        cities.insert({City::NewYork, NewYork});

        City_info Osaka(Color::Red, vector<City>{City::Taipei, City::Tokyo}, "Osaka        ");
        cities.insert({City::Osaka, Osaka});

        City_info Paris(Color::Blue, vector<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}, "Paris        ");
        cities.insert({City::Paris, Paris});

        City_info Riyadh(Color::Black, vector<City>{City::Baghdad, City::Cairo, City::Karachi}, "Riyadh       ");
        cities.insert({City::Riyadh, Riyadh});

        City_info SanFrancisco(Color::Blue, vector<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}, "SanFrancisco " );
        cities.insert({City::SanFrancisco, SanFrancisco});

        City_info Santiago(Color::Yellow, vector<City>{City::Lima}, "Santiago     ");
        cities.insert({City::Santiago, Santiago});

        City_info SaoPaulo(Color::Yellow, vector<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}, "SaoPaulo     ");
        cities.insert({City::SaoPaulo, SaoPaulo});

        City_info Seoul(Color::Red, vector<City>{City::Beijing, City::Shanghai, City::Tokyo}, "Seoul        ");
        cities.insert({City::Seoul, Seoul});

        City_info Shanghai(Color::Red, vector<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}, "Shanghai     ");
        cities.insert({City::Shanghai, Shanghai});

        City_info StPetersburg(Color::Blue, vector<City>{City::Essen, City::Istanbul, City::Moscow}, "StPetersburg ");
        cities.insert({City::StPetersburg, StPetersburg});

        City_info Sydney(Color::Red, vector<City>{City::Jakarta, City::Manila, City::LosAngeles}, "Sydney       ");
        cities.insert({City::Sydney, Sydney});

        City_info Taipei(Color::Red, vector<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila}, "Taipei       ");
        cities.insert({City::Taipei, Taipei});

        City_info Tehran(Color::Black, vector<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}, "Tehran       ");
        cities.insert({City::Tehran, Tehran});

        City_info Tokyo(Color::Red, vector<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}, "Tokyo        ");
        cities.insert({City::Tokyo, Tokyo});

        City_info Washington(Color::Blue, vector<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami}, "Washington   ");
        cities.insert({City::Washington, Washington});
    }

}