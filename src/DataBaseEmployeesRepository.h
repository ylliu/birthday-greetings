//
// Created by youlong on 2021/8/16.
//

#ifndef BIRTHDAYGREETING_DATABASEEMPLOYEEREPOSITORY_H
#define BIRTHDAYGREETING_DATABASEEMPLOYEEREPOSITORY_H


#include "EmployeesRepository.h"

class DataBaseEmployeesRepository : public EmployeesRepository {

public:
    std::vector<Employee> findEmployeesWhoseBirthdayIs(XDate *today) override;
};


#endif //BIRTHDAYGREETING_DATABASEEMPLOYEEREPOSITORY_H
