//
// Created by youlong on 2021/8/23.
//

#include "MailSender.h"
#include <fstream>
#include "json.h"

void MailSender::sendGreetingsTo(Employee &employee) {
    SmtpMessage smtpMessage = constructMessage(employee);
    //连接网络端口设置邮箱地址密码
    logGreetings(smtpMessage);
}

void MailSender::logGreetings(SmtpMessage &smtpMessage) const {
    std::ofstream greetings;
    greetings.open("greetings.json");
    if (!greetings) {
        std::cerr << "Can't open greetings.log" << std::endl;
    }
    Json::Value greetingItem;
    greetingItem["Subject"] = smtpMessage.getHeaderValue("Subject");
    greetingItem["From"] = smtpMessage.getSender();
    greetingItem["To"] = smtpMessage.getHeaderValue("To");
    greetingItem["Body"] = smtpMessage.getBody();
    greetings << greetingItem.toStyledString();
    greetings.close();
}


SmtpMessage MailSender::constructMessage(Employee &employee) const {
    SmtpMessage smtpMessage;
    smtpMessage.setBody("Happy Birthday, dear " + employee.getFirstName() + "!");
    smtpMessage.setSubject("Happy Birthday!");
    smtpMessage.setRecipient("sender@gmail.com", employee.getEmail());
    return smtpMessage;
}