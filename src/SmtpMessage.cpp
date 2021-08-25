//
// Created by youlong on 2021/8/23.
//

#include <vector>
#include <iosfwd>
#include <system_error>
#include "SmtpMessage.h"

SmtpMessage::SmtpMessage() {}

std::string SmtpMessage::getBody() {
    return body;
}

std::string SmtpMessage::getHeaderValue(std::string key) {
    if (key == "Subject") {
        return subject;
    }
    if(key=="To"){
        return receiver;
    }
    return "";
}

void SmtpMessage::setBody(std::string body) {
    this->body = body;
}

void SmtpMessage::setSubject(std::string subject) {
    this->subject = subject;
}

void SmtpMessage::setRecipient(std::string sender, std::string receiver) {
    this->sender = sender;
    this->receiver = receiver;
}

std::string SmtpMessage::getSender() {
    return sender;
}
