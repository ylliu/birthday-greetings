#include <gtest/gtest.h>
#include "../src/DataBaseEmployeesRepository.h"
#include "../src/Employee.h"
#include <libpq-fe.h>


class DataBaseEmployeeRepositoryTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(DataBaseEmployeeRepositoryTest, should_find_employees_from_database_whose_birthday_is_today) {
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

    std::vector<Employee> expectEmployees;
    Employee employee1("Doe", "John", "1990/12/08", "john.doe@gmail.com");
    expectEmployees.push_back(employee1);
    //When
    DataBaseEmployeesRepository dataBaseEmployeeRepository;
    std::vector<Employee> employees = dataBaseEmployeeRepository.findEmployeesWhoseBirthdayIs(new XDate("2021/12/08"));
    //Then
    EXPECT_EQ(expectEmployees, employees);
}
