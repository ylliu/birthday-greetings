//
// Created by youlong on 2021/8/19.
//

#include <iosfwd>
#include <iostream>
#include "Employee.h"

Employee::Employee(std::string lastName,
                   std::string firstName,
                   std::string dateOfBirth,
                   std::string email) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->dateOfBirth = new XDate(dateOfBirth);
    this->email = email;
}

bool Employee::isBirthday(XDate today) {
    return dateOfBirth->isSameDay(today);
}

bool Employee::operator==(const Employee &rhs) const {
    return lastName == rhs.lastName &&
           firstName == rhs.firstName &&
           dateOfBirth->isSameDay(*rhs.dateOfBirth) &&
           email == rhs.email;
}

bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}

std::string Employee::getFirstName() {
    return firstName;
}

std::string Employee::getEmail() {
    return email;
}
