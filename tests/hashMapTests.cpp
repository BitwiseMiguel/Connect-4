#include "testFunctions.hpp"
#include "../runTests.hpp"
#include "../src/hashMap.hpp"

void runHashMapTests() {

    std::cout << ansi::foreground_yellow << "HASHMAP TESTS" << ansi::reset << std::endl;
    
    { // Constructor Test

        HashMap map;

        EQ_TEST((std::vector<uint8_t>){map.get(0), map.get(1), map.get(2)},
            (std::vector<uint8_t>){222, 222, 222}, "Constructor Test");
    }

    { // Function Put Test 1

        HashMap map;
        auto key1 = 3ULL;
        auto key2 = (1ULL << 19) + 2ULL;

        uint8_t value = 5;

        map.put(key1, value);


        EQ_TEST((std::vector<uint8_t>){map.get(key1), map.get(key2)},
            (std::vector<uint8_t>){value, 222}, "Function Put Test 1");
    }

};
