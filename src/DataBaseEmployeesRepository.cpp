//
// Created by youlong on 2021/8/16.
//

#include "DataBaseEmployeesRepository.h"
#include <iostream>
#include <libpq-fe.h>

std::vector<Employee> DataBaseEmployeesRepository::findEmployeesWhoseBirthdayIs(XDate *today) {
    std::vector<Employee> result;

    const char conninfo[] = "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return {};
    }

    PGresult *res = nullptr;
    res = PQexec(conn, "SELECT * FROM employee;");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        return {};
    }
    for (int i = 0; i < PQntuples(res); i++) {
        std::string lastName = PQgetvalue(res, i, 1);
        std::string firstName = PQgetvalue(res, i, 2);
        std::string birthOfDate = PQgetvalue(res, i, 3);
        std::string email = PQgetvalue(res, i, 4);
        Employee employee(lastName, firstName, birthOfDate, email);
        if(employee.isBirthday(*today)){
            result.push_back(employee);
        }
    }
    PQclear(res);
    return result;
}


