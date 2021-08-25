//
// Created by youlong on 2021/8/22.
//

#include <iosfwd>
#include "XDate.h"

XDate::XDate(std::string yyyyMMdd) {
    this->date = boost::gregorian::from_simple_string(yyyyMMdd);
}

int XDate::day() {
    return this->date.day().as_number();
}

int XDate::month() {
    return this->date.month().as_number();
}

bool XDate::isSameDay(XDate anotherDate) {
    return this->date.month() == anotherDate.month() && this->day() == anotherDate.day();
}
