#include <gtest/gtest.h>
#include <libpq-fe.h>
#include "../src/XDate.h"
#include "../src/BirthdayService.h"
#include "../src/DataBaseEmployeesRepository.h"
#include "../src/MailSender.h"
#include "../lib/json/json.h"
#include <fstream>

class AcceptanceTest : public ::testing::Test {
protected:
    void SetUp() override {
        birthdayService = new BirthdayService(new DataBaseEmployeesRepository(), new MailSender());
    }

    void TearDown() override {

    }

    BirthdayService *birthdayService;
};

TEST_F(AcceptanceTest, will_send_greetings_when_its_somebodys_birthday) {
    //Given
    //往数据库里面写数据
    const char conninfo[] = "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
    }
    PQexec(conn, "DELETE from employee");
    PQexec(conn, "INSERT INTO employee VALUES (1, 'Doe','John','1990/12/08','john.doe@gmail.com')");
    PQexec(conn, "INSERT INTO employee VALUES (2, 'Ann','Mary','1995/10/01','mary.ann@gmail.com')");
    //when
    birthdayService->sendGreetings(new XDate("2021/12/08"));
    //then
    //断言log
    std::string line;
    std::ifstream greetings("greetings.json");
    if (greetings.is_open()) {
        Json::Value greetingItem;
        if (Json::Reader().parse(greetings, greetingItem, FALSE)) {
            EXPECT_EQ("Happy Birthday!", greetingItem["Subject"].asString());
            EXPECT_EQ("sender@gmail.com", greetingItem["From"].asString());
            EXPECT_EQ("john.doe@gmail.com", greetingItem["To"].asString());
            EXPECT_EQ("Happy Birthday, dear John!", greetingItem["Body"].asString());
        }
    }
    greetings.close();
    remove("greetings.json");
}

TEST_F(AcceptanceTest, will_not_send_greetings_when_nobody_birthday) {
    //Given
    //往数据库里面写数据
    const char conninfo[] = "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
    }
    PQexec(conn, "DELETE from employee");
    PQexec(conn, "INSERT INTO employee VALUES (1, 'Doe','John','1990/12/08','john.doe@gmail.com')");
    PQexec(conn, "INSERT INTO employee VALUES (2, 'Ann','Mary','1995/10/01','mary.ann@gmail.com')");
    //when
    birthdayService->sendGreetings(new XDate("2021/12/09"));
    //then
    std::string line;
    std::ifstream greetings("greetings.json");
    EXPECT_FALSE(greetings.is_open());
    greetings.close();

}
