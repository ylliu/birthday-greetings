//
// Created by youlong on 2021/8/23.
//

#ifndef BOOST_MAILSENDER_H
#define BOOST_MAILSENDER_H


#include "SmtpMessage.h"
#include "Employee.h"
#include "GreetingsSender.h"
class MailSender : public GreetingsSender{

public:
    void sendGreetingsTo(Employee &employee) override;

    SmtpMessage constructMessage(Employee &employee) const;

    void logGreetings(SmtpMessage &smtpMessage) const;
};


#endif //BOOST_MAILSENDER_H
