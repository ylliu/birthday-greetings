project(BirthdayGreeting)
cmake_minimum_required(VERSION 3.20)

set(BOOST_INCLUDEDIR  $ENV{BOOST_INCLUDEDIR})
set(BOOST_LIBRARYDIR   $ENV{BOOST_LIBRARYDIR})

include_directories(${BOOST_INCLUDEDIR})
link_directories(${BOOST_LIBRARYDIR})

add_executable(${PROJECT_NAME} main.cpp src/XDate.h)
target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARYDIR})

add_subdirectory(src)
add_subdirectory(test)