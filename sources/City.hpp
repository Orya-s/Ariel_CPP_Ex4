#pragma once
#include "Color.hpp"
#include <vector>
#include <string>
#include <iostream>


namespace pandemic {

	// Defines a city on the board
	enum City {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
	};


    class City_info
    {
        private:
            int pandemic_level;
            bool research_station;
                
        public:
            Color color;  // public because doesn't change between games
            std::vector<City> neighbors;
            std::string name;

            City_info(Color c, std::vector<City> n) : color(c) , neighbors(n), research_station(false), pandemic_level(0) {}
            City_info(Color c, std::vector<City> n, std::string name) : 
                color(c) , neighbors(n), research_station(false), pandemic_level(0), name(name) {}

            ~City_info() {}

            int& get_cubes() 
            {
                return pandemic_level;
            }
            const bool has_station() const
            {
                return research_station;
            }
            void build_station()
            {
                research_station = true;
            }
            void remove_station() 
            {
                research_station = false;
            }
            friend std::ostream& operator<< (std::ostream& os, const City_info& city)
            {
                return os << "\e[1m" << city.name << "\e[0m"<< "  "   
                    << " disease cubes - " <<  "\033[1;36m" << city.pandemic_level << "\033[0m"
                    << " , research station - " << "\033[1;36m" << city.has_station() << "\033[0m";
            }

    };



}