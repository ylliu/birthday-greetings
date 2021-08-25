//
// Created by youlong on 2021/8/23.
//

#ifndef BOOST_BIRTHDAYSERVICE_H
#define BOOST_BIRTHDAYSERVICE_H


#include "SmtpMessage.h"
#include "XDate.h"
#include "EmployeesRepository.h"
#include "GreetingsSender.h"

class BirthdayService {

public:
    BirthdayService();

    BirthdayService(EmployeesRepository *employeesRepository, GreetingsSender *greetingsSender);

    ~BirthdayService() {}

    void sendGreetings(XDate *xDate);

private:
    EmployeesRepository *employeesRepository;

    GreetingsSender *greetingsSender;
};


#endif //BOOST_BIRTHDAYSERVICE_H
