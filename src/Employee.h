//
// Created by youlong on 2021/8/19.
//

#ifndef BIRTHDAYGREETING_EMPLOYEE_H
#define BIRTHDAYGREETING_EMPLOYEE_H

#include <string>
#include "XDate.h"
class Employee {

public:
    Employee(std::string lastName, std::string firstName, std::string dateOfBirth, std::string email);
    bool isBirthday(XDate today);

    bool operator==(const Employee &rhs) const;

    bool operator!=(const Employee &rhs) const;

    std::string getFirstName();

    std::string getEmail();

private:
    std::string lastName;
    std::string firstName;
    XDate* dateOfBirth;
    std::string email;
};


#endif //BIRTHDAYGREETING_EMPLOYEE_H
