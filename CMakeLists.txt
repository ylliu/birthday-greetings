project( BirthdayGreeting )
cmake_minimum_required( VERSION 3.20 )
set(BOOST_ROOT D:/DevelopmentEnviroment/boost_1_77_0)
set(BOOST_INCLUDEDIR  D:/DevelopmentEnviroment/boost_1_77_0)
set(BOOST_LIBRARYDIR  D:/DevelopmentEnviroment/boost_1_77_0/lib64-msvc-14.1)

find_package( boost 1.77.0 )
include_directories( ${BOOST_INCLUDEDIR} )
LINK_DIRECTORIES( ${BOOST_LIBRARYDIR} )



message(${BOOST_INCLUDEDIR})


add_executable( ${PROJECT_NAME} main.cpp src/XDate.h)
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

add_subdirectory(src)
add_subdirectory(test)