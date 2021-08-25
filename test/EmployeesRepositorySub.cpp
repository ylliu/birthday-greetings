//
// Created by youlong on 2021/8/23.
//

#include "EmployeesRepositorySub.h"

std::vector<Employee> EmployeesRepositorySub::findEmployeesWhoseBirthdayIs(XDate *today) {
    std::vector<Employee> result;
    for (Employee employee:employees) {
        if (employee.isBirthday(*today)) {
            result.push_back(employee);
        }
    }
    return result;
}

void EmployeesRepositorySub::addEmployee(Employee employee) {
    employees.push_back(employee);
}
