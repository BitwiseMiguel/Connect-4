#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <stdint.h>

/**
 * @brief The HashMap class represents a hash map data structure.
 */
class HashMap {
private:
    /**
     * @brief The Data class represents a key-value pair stored in the hash map.
     */
    class Data {
    public:
        uint64_t key : 56; // The key of the key-value pair (56-bits).
        uint8_t value; // The value associated with the key.

        /**
         * @brief Constructs a Data object with default values.
         */
        Data()
            : key(0ULL), value(DEADCODE) {};
    };

    Data* table;

    uint32_t size;

    /**
     * @brief Helper function to calculate the index based on the key.
     * @param key The key to calculate the index for.
     * @return The calculated index value.
     */
    uint32_t calculateIndex(const uint64_t key) const {
        return (uint32_t) (key % size);
    }

public:
    static const uint8_t DEADCODE{(uint8_t)0xDEADC0DE}; // No data (number 222).
    
    /**
     * @brief Constructs a HashMap object with a specified size.
     * @param theSize The size of the HashMap. Default value is (1ULL << 19) - 1ULL.
     * M_19 = (1ULL << 19) - 1ULL is the 7th Mersenne prime.
     */
    HashMap(const uint32_t &theSize = (1ULL << 19) - 1ULL);

    /**
     * @brief Copy constructor for the HashMap class.
     * @param other The HashMap object to be copied.
     */
    HashMap(const HashMap &other);

    /**
     * @brief Move constructor for the HashMap class.
     * @param other The HashMap object to be moved.
     */
    HashMap(HashMap &&other);
    
    /**
     * @brief Destructor for the HashMap class.
     */
    ~HashMap();

    /**
     * @brief Inserts a key-value pair into the HashMap.
     * @param key The key to be inserted.
     * @param value The value to be associated with the key.
     */
    void put(const uint64_t &key, const uint8_t &value);

    /**
     * @brief Retrieves the value associated with a given key from the HashMap.
     * @param key The key to retrieve the value for.
     * @return The value associated with the key.
     */
    uint8_t get(const uint64_t &key) const;

};

#endif
