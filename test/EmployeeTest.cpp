#include <gtest/gtest.h>
#include "../src/Employee.h"

class EmployeeTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(EmployeeTest, test_birthday) {
    Employee employee("Doe", "John", "1990/12/08", "john.doe@gmail.com");
    XDate birthday("2021/12/08");
    XDate notBirthday("2021/12/09");
    EXPECT_TRUE(employee.isBirthday(birthday));
    EXPECT_FALSE(employee.isBirthday(notBirthday));
}

