//
// Created by youlong on 2021/8/24.
//

#ifndef BOOST_GREETINGSSENDER_H
#define BOOST_GREETINGSSENDER_H


#include "SmtpMessage.h"
#include "Employee.h"

class GreetingsSender {
public:
    virtual void sendGreetingsTo(Employee &employee) = 0;
};


#endif //BOOST_GREETINGSSENDER_H
