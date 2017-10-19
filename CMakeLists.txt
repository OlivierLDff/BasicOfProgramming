cmake_minimum_required(VERSION 2.8)
project("Basic Of Programming")

#Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if ( MSVC )
	#use of standard function like strcpy
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif()

if( UNIX )
	set(CMAKE_C_COMPILER_INIT g++)
	find_package (Threads)
	#set(CMAKE_CXX_FLAGS "-g -O3 -std=c++11")
	set(CMAKE_CXX_FLAGS "-g -Wall")

	add_definitions(-Dnullptr=NULL)
	add_definitions(-Doverride=)
endif()

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/bin_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/lib_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/lib_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
add_subdirectory(lab5)
add_subdirectory(lab6)
add_subdirectory(lab7)