//
// Created by youlong on 2021/8/22.
//

#ifndef BIRTHDAYGREETING_XDATE_H
#define BIRTHDAYGREETING_XDATE_H
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
class XDate {

public:
    XDate(std::string yyyyMMdd);

    int month();

    int day();

    bool isSameDay(XDate anotherDate);

private:
    boost::gregorian::date date;
};


#endif //BIRTHDAYGREETING_XDATE_H
