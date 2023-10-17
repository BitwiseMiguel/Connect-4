#ifndef TESTFUNCTIONS_HPP
#define TESTFUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>

namespace ansi {
    template < class CharT, class Traits >
    constexpr
    std::basic_ostream< CharT, Traits > & reset( std::basic_ostream< CharT, Traits > &os )
    {return os << "\033[0m";}

    template < class CharT, class Traits >
    constexpr
    std::basic_ostream< CharT, Traits > & foreground_green( std::basic_ostream< CharT, Traits > &os )
    {return os << "\033[32m";}

    template < class CharT, class Traits >
    constexpr
    std::basic_ostream< CharT, Traits > & foreground_boldred( std::basic_ostream< CharT, Traits > &os )
    {return os << "\033[1m\033[31m";}

    template < class CharT, class Traits >
    constexpr
    std::basic_ostream< CharT, Traits > & foreground_yellow( std::basic_ostream< CharT, Traits > &os )
    {return os << "\033[33m";}
}

template <typename T>
void EQ_TEST(T lhs, T rhs, std::string test_name) {
    if (lhs == rhs) {
        std::cout << ansi::foreground_green << test_name << " sucessfull!" << ansi::reset << std::endl;
    } else {
        std::cout << ansi::foreground_boldred << test_name << " failed!" << ansi::reset << std::endl;
        std::cout << ansi::foreground_yellow << "Expected " << lhs << " = " << rhs << "." << ansi::reset << std::endl;
    }
}

template <typename T>
void EQ_TEST(std::vector<T> lhs, std::vector<T> rhs, std::string test_name) {
    for (uint32_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            std::cout << ansi::foreground_boldred << test_name << " failed!" << ansi::reset << std::endl;
            std::cout << ansi::foreground_yellow << "At index " << i << " expected " << lhs[i] << " = " << rhs[i] << "." << ansi::reset << std::endl;
            return;
        }
    }
    std::cout << ansi::foreground_green << test_name << " sucessfull!" << ansi::reset << std::endl;
}

#endif