cmake_minimum_required(VERSION 3.9)
project(cinema_booking_system)

set(CMAKE_CXX_STANDARD 11)

add_executable(cinema_booking_system
        cinema-booking-system.cpp
        Cinema.cpp
        Cinema.hpp
        Client.cpp
        Client.hpp
        Movie.cpp
        Movie.hpp
        Sit.cpp
        Sit.hpp)
