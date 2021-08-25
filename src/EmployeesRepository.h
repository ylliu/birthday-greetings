//
// Created by youlong on 2021/8/23.
//

#ifndef BOOST_EMPLOYEESREPOSITORY_H
#define BOOST_EMPLOYEESREPOSITORY_H

#include <vector>
#include "Employee.h"
class EmployeesRepository {
public:
    virtual std::vector<Employee> findEmployeesWhoseBirthdayIs(XDate* today) = 0;
};

#endif //BOOST_EMPLOYEESREPOSITORY_H
