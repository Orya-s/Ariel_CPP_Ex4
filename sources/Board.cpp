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

    bool Board::is_cured(Color c)
    {
        return count(found_cure.begin(), found_cure.end(), c) != 0;
    }


    std::ostream& operator<< (std::ostream& output, const Board& board)
    {
        output << "Cures discoverd so far: ";

        // for (vector<Color>::const_iterator ii = board.found_cure.begin(); ii != board.found_cure.end(); ++ii)
        // {
        //     if (*ii == Color::Black)
        //     {
        //         output << "Black";
        //     }
        //     else if (*ii == Color::Blue)
        //     {
        //         output << "Blue";    
        //     }
        //     else if (*ii == Color::Red)
        //     {
        //         output << "Red"; 
        //     }
        //     else
        //     {
        //         output << "Yellow"; 
        //     }
        // }
        output << "\n";

        // printing cubes and station for each city
    
        return output;
    }



    void Board::init()
    {
        City_info Algiers(Color::Black, vector<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo} );
        cities.insert({City::Algiers, Algiers});

        City_info Atlanta(Color::Blue, vector<City>{City::Chicago, City::Miami, City::Washington} );
        cities.insert({City::Atlanta, Atlanta});
        
        City_info Baghdad(Color::Black, vector<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi} );
        cities.insert({City::Baghdad, Baghdad});
    
        City_info Bangkok(Color::Red, vector<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong} );
        cities.insert({City::Bangkok, Bangkok});

        City_info Beijing(Color::Red, vector<City>{City::Shanghai, City::Seoul} );
        cities.insert({City::Beijing, Beijing});

        City_info Bogota(Color::Yellow, vector<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires} );
        cities.insert({City::Bogota, Bogota});

        City_info BuenosAires(Color::Yellow, vector<City>{City::Bogota, City::SaoPaulo} );
        cities.insert({City::BuenosAires, BuenosAires});

        City_info Cairo(Color::Black, vector<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh} );
        cities.insert({City::Cairo, Cairo});

        City_info Chennai(Color::Black, vector<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta} );
        cities.insert({City::Chennai, Chennai});

        City_info Chicago(Color::Blue, vector<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal} );
        cities.insert({City::Chicago, Chicago});

        City_info Delhi(Color::Black, vector<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata} );
        cities.insert({City::Delhi, Delhi});

        City_info Essen(Color::Blue, vector<City>{City::London, City::Paris, City::Milan, City::StPetersburg} );
        cities.insert({City::Essen, Essen});

        City_info HoChiMinhCity(Color::Red, vector<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila} );
        cities.insert({City::HoChiMinhCity, HoChiMinhCity});

        City_info HongKong(Color::Red, vector<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei} );
        cities.insert({City::HongKong, HongKong});

        City_info Istanbul(Color::Black, vector<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow} );
        cities.insert({City::Istanbul, Istanbul});

        City_info Jakarta(Color::Red, vector<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney} );
        cities.insert({City::Jakarta, Jakarta});

        City_info Johannesburg(Color::Yellow, vector<City>{City::Kinshasa, City::Khartoum} );
        cities.insert({City::Johannesburg, Johannesburg});

        City_info Karachi(Color::Black, vector<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi} );
        cities.insert({City::Karachi, Karachi});

        City_info Khartoum(Color::Yellow, vector<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg} );
        cities.insert({City::Khartoum, Khartoum});

        City_info Kinshasa(Color::Yellow, vector<City>{City::Lagos, City::Khartoum, City::Johannesburg} );
        cities.insert({City::Kinshasa, Kinshasa});

        City_info Kolkata(Color::Black, vector<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong} );
        cities.insert({City::Kolkata, Kolkata});

        City_info Lagos(Color::Yellow, vector<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa} );
        cities.insert({City::Lagos, Lagos});

        City_info Lima(Color::Yellow, vector<City>{City::MexicoCity, City::Bogota, City::Santiago} );
        cities.insert({City::Lima, Lima});

        City_info London(Color::Blue, vector<City>{City::NewYork, City::Madrid, City::Essen, City::Paris} );
        cities.insert({City::London, London});

        City_info LosAngeles(Color::Yellow, vector<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney} );
        cities.insert({City::LosAngeles, LosAngeles});

        City_info Madrid(Color::Blue, vector<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers} );
        cities.insert({City::Madrid, Madrid});

        City_info Manila(Color::Red, vector<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong} );
        cities.insert({City::Manila, Manila});

        City_info MexicoCity(Color::Yellow, vector<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota} );
        cities.insert({City::MexicoCity, MexicoCity});

        City_info Miami(Color::Yellow, vector<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota} );
        cities.insert({City::Miami, Miami});

        City_info Milan(Color::Blue, vector<City>{City::Essen, City::Paris, City::Istanbul} );
        cities.insert({City::Milan, Milan});

        City_info Montreal(Color::Blue, vector<City>{City::Chicago, City::Washington, City::NewYork} );
        cities.insert({City::Montreal, Montreal});

        City_info Moscow(Color::Black, vector<City>{City::StPetersburg, City::Istanbul, City::Tehran} );
        cities.insert({City::Moscow, Moscow});

        City_info Mumbai(Color::Black, vector<City>{City::Karachi, City::Delhi, City::Chennai} );
        cities.insert({City::Mumbai, Mumbai});

        City_info NewYork(Color::Blue, vector<City>{City::Montreal, City::Washington, City::London, City::Madrid} );
        cities.insert({City::NewYork, NewYork});

        City_info Osaka(Color::Red, vector<City>{City::Taipei, City::Tokyo} );
        cities.insert({City::Osaka, Osaka});

        City_info Paris(Color::Blue, vector<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London} );
        cities.insert({City::Paris, Paris});

        City_info Riyadh(Color::Black, vector<City>{City::Baghdad, City::Cairo, City::Karachi} );
        cities.insert({City::Riyadh, Riyadh});

        City_info SanFrancisco(Color::Blue, vector<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila} );
        cities.insert({City::SanFrancisco, SanFrancisco});

        City_info Santiago(Color::Yellow, vector<City>{City::Lima} );
        cities.insert({City::Santiago, Santiago});

        City_info SaoPaulo(Color::Yellow, vector<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid} );
        cities.insert({City::SaoPaulo, SaoPaulo});

        City_info Seoul(Color::Red, vector<City>{City::Beijing, City::Shanghai, City::Tokyo} );
        cities.insert({City::Seoul, Seoul});

        City_info Shanghai(Color::Red, vector<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo} );
        cities.insert({City::Shanghai, Shanghai});

        City_info StPetersburg(Color::Blue, vector<City>{City::Essen, City::Istanbul, City::Moscow} );
        cities.insert({City::StPetersburg, StPetersburg});

        City_info Sydney(Color::Red, vector<City>{City::Jakarta, City::Manila, City::LosAngeles} );
        cities.insert({City::Sydney, Sydney});

        City_info Taipei(Color::Red, vector<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila} );
        cities.insert({City::Taipei, Taipei});

        City_info Tehran(Color::Black, vector<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi} );
        cities.insert({City::Tehran, Tehran});

        City_info Tokyo(Color::Red, vector<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco} );
        cities.insert({City::Tokyo, Tokyo});

        City_info Washington(Color::Blue, vector<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami} );
        cities.insert({City::Washington, Washington});
    }

}