cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(THE_experiments)

set(Boost_USE_STATIC_LIBS ON)

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})


find_package(Boost 1.71.0 COMPONENTS filesystem system program_options log log_setup REQUIRED)
#set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY})
if(Boost_FOUND)
	MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${BOOST_LIBRARYDIR}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(par_deriv)
add_subdirectory(memory)
add_subdirectory(1)
add_subdirectory(filesystem)
add_subdirectory(boost_tests)
add_subdirectory(curl)
add_subdirectory(2)
add_subdirectory(sof)
add_subdirectory(new_prefsum)
