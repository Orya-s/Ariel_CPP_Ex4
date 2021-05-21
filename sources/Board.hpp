#pragma once
#include "City.hpp"
#include <iostream>
#include <set>
#include <map>

namespace pandemic {

    class Board
    {
        private:
            std::set<Color> found_cure;              
            void init();

        public:
            std::map<City, City_info> cities;

            Board() 
            {
                init();
            }
            ~Board() {}

            int& operator[] (City city) ;  
            bool is_clean();
            void remove_cures() ;  
            void remove_stations() ;
            void add_cure(Color c);
            bool is_cured(Color c) const;
            friend std::ostream& operator<< (std::ostream& output, const Board& board);
    };

}    
