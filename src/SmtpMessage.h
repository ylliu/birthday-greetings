//
// Created by youlong on 2021/8/23.
//

#ifndef BOOST_SMTPMESSAGE_H
#define BOOST_SMTPMESSAGE_H

#include <string>
#include <vector>
#include <iosfwd>

class SmtpMessage {

public:
    SmtpMessage();

    std::string getBody();

    std::string getHeaderValue(std::string key);

    void setBody(std::string body);

    void setSubject(std::string subject);

    void setRecipient(std::string sender, std::string receiver);

    std::string getSender();

private:
    std::string body;
    std::string subject;
    std::string sender;
    std::string receiver;
};


#endif //BOOST_SMTPMESSAGE_H
