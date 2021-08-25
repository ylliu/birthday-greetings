project(birthday_greeting_lib)
cmake_minimum_required(VERSION 3.20)

# Custom location of the PostgreSQL library
set(PostgreSQL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../PostgreSQL13")

set(PostgreSQL_LIBRARY_DIR "${PostgreSQL_DIR}/lib")
set(PostgreSQL_INCLUDE_DIRS "${PostgreSQL_DIR}/include")

set(HEADER_FILES
        XDate.h
        DataBaseEmployeesRepository.h
        Employee.h
        BirthdayService.h
        SmtpMessage.h
        MailSender.h
        EmployeesRepository.h
        GreetingsSender.h
        )

set(SOURCE_FILES
        XDate.cpp
        DataBaseEmployeesRepository.cpp
        Employee.cpp
        BirthdayService.cpp
        SmtpMessage.cpp
        MailSender.cpp
        )

include_directories(${BOOST_INCLUDEDIR})
LINK_DIRECTORIES(${BOOST_LIBRARYDIR})

# json
include_directories(../lib/json)
# Include the found INCLUDE directory
include_directories(${PostgreSQL_INCLUDE_DIRS})

link_directories(${PostgreSQL_LIBRARY_DIRS})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARYDIR})
target_link_libraries(${PROJECT_NAME} libjsoncpp.a)