project(birthday_greeting_test)

set(gtest_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../lib/googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
link_directories(../lib)

enable_testing()

set(PostgreSQL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../PostgreSQL13")
set(PostgreSQL_INCLUDE_DIRS "${PostgreSQL_DIR}/include")
# Include the found INCLUDE directory
set(PostgreSQL_LIBRARIES "${PostgreSQL_DIR}/lib/libpq.lib")

set(SOURCE_FILES
        XDateTest.cpp
        DataBaseEmployeeRepositoryTest.cpp
        EmployeeTest.cpp
        BirthdayServiceTest.cpp
        EmployeesRepositorySub.cpp
        AcceptanceTest.cpp
        )
include_directories(${PostgreSQL_INCLUDE_DIRS})

add_executable(birthday_greeting_test_run ${SOURCE_FILES})

target_link_libraries(birthday_greeting_test_run birthday_greeting_lib)
target_link_libraries(birthday_greeting_test_run libgtest.a libgtest_main.a)
target_link_libraries(birthday_greeting_test_run ${PostgreSQL_LIBRARIES})
target_link_libraries(birthday_greeting_test_run libjsoncpp.a)