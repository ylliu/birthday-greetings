//
// Created by youlong on 2021/8/23.
//

#ifndef BOOST_EMPLOYEESREPOSITORYSUB_H
#define BOOST_EMPLOYEESREPOSITORYSUB_H

#include "../src/EmployeesRepository.h"

class EmployeesRepositorySub : public EmployeesRepository {

public:
    std::vector<Employee> findEmployeesWhoseBirthdayIs(XDate *today) override;

    void addEmployee(Employee employee);

private:
    std::vector<Employee> employees;
};


#endif //BOOST_EMPLOYEESREPOSITORYSUB_H
