#include <gtest/gtest.h>
#include "../src/XDate.h"
#include "../src/BirthdayService.h"
#include "EmployeesRepositorySub.h"
#include "../src/MailSender.h"
#include "../lib/json/json.h"
#include <fstream>

class BirthdayServiceTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(BirthdayServiceTest, will_send_greetings_when_its_somebodys_birthday_using_testsub) {
    //given
    EmployeesRepositorySub *employeesRepositorySub = new EmployeesRepositorySub();
    employeesRepositorySub->addEmployee(Employee("Doe", "John", "1990/12/08", "john.doe@gmail.com"));
    employeesRepositorySub->addEmployee(Employee("Ann", "Mary", "1995/10/01", "mary.ann@gmail.com"));
    //when
    BirthdayService birthdayService(employeesRepositorySub, new MailSender());
    birthdayService.sendGreetings(new XDate("2021/12/08"));
    //断言log
    std::string line;
    std::ifstream greetings("greetings.json");
    if (greetings.is_open()) {
        Json::Reader reader;
        Json::Value greetingItem;
        if (reader.parse(greetings, greetingItem, FALSE)) {
            EXPECT_EQ("Happy Birthday!", greetingItem["Subject"].asString());
            EXPECT_EQ("sender@gmail.com", greetingItem["From"].asString());
            EXPECT_EQ("john.doe@gmail.com", greetingItem["To"].asString());
            EXPECT_EQ("Happy Birthday, dear John!", greetingItem["Body"].asString());
        }
    }
    greetings.close();
    remove("greetings.json");
}