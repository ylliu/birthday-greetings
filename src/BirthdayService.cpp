//
// Created by youlong on 2021/8/23.
//

#include "BirthdayService.h"

BirthdayService::BirthdayService(EmployeesRepository *employeesRepository, GreetingsSender *greetingsSender) {
    this->employeesRepository = employeesRepository;
    this->greetingsSender = greetingsSender;
}

void BirthdayService::sendGreetings(XDate *xDate) {
    std::vector<Employee> employees = employeesRepository->findEmployeesWhoseBirthdayIs(xDate);
    for (Employee employee:employees) {
        greetingsSender->sendGreetingsTo(employee);
    }
//    std::for_each(employees.begin(),employees.end(),[&](Employee e){greetingsSender->sendGreetingsTo(e);});
}

