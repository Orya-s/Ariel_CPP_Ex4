#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic {

    OperationsExpert &OperationsExpert::build() 
    {
        board.cities.at(location).build_station();
        return *this;
    }

    string OperationsExpert::role() 
    {
        return "OperationsExpert";
    }
}
