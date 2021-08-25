project(birthday_greeting_lib)
cmake_minimum_required(VERSION 3.20)
set(BOOST_ROOT D:/DevelopmentEnviroment/boost_1_77_0)
set(BOOST_INCLUDEDIR D:/DevelopmentEnviroment/boost_1_77_0)
set(BOOST_LIBRARYDIR D:/DevelopmentEnviroment/boost_1_77_0/lib64-msvc-14.1)

# Custom location of the PostgreSQL library
set(PostgreSQL_DIR "C:/Users/youlong/CLionProjects/BirthdayGreeting/PostgreSQL13")
set(PostgreSQL_ROOT "${PostgreSQL_DIR}")
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

find_package(boost 1.77.0)
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