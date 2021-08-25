#include <iostream>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace boost::gregorian;

int main() {
    std::string line;
    date d = from_simple_string("1990/09/10");
    std::cout<<"year:"<<d.year()<<std::endl;
    std::cout<<"month:"<<d.month()<<std::endl;
    std::cout<<"day:"<<d.day()<<std::endl;
}

#include "boost/date_time/gregorian/gregorian.hpp"
