#ifndef UINT128_API_HPP
#define UINT128_API_HPP

#include <stdint.h>
#include <iostream>

/**
 * @class uint128_t
 * A class representing a 128-bit unsigned integer.
 */
class uint128_t {
private:
    uint64_t head;
    uint64_t tail;
    
public:
    /**
     * @brief Constructor.
     * Initializes the 128-bit integer with the given tail value.
     * @param theTail The least significant 64 bits of the 128-bit integer. Default value is 0.
     */
    uint128_t(const uint64_t& theTail = 0);

    /**
     * @brief Constructor.
     * Initializes the 128-bit integer with the given head and tail values.
     * @param theHead The most significant 64 bits of the 128-bit integer.
     * @param theTail The least significant 64 bits of the 128-bit integer.
     */
    uint128_t(const uint64_t& theHead, const uint64_t& theTail);

    /**
     * @brief Constructor.
     * Initializes the 128-bit integer with the given other 128-bit integer.
     * @param other The 128-bit integer.
     */
    uint128_t(const uint128_t& other);

    /**
     * @brief Equality operator.
     * Checks if two 128-bit integers are equal.
     * @param other The other 128-bit integer to compare.
     * @return True if the two 128-bit integers are equal, false otherwise.
     */
    bool operator==(const uint128_t& other) const;

    /**
     * @brief Equality operator.
     * Checks if a 128-bit integer and a 64-bit integer have the same value.
     * @param other The 64-bit integer to compare.
     * @return True if the integers have the same value, false otherwise.
     */
    bool operator==(const uint64_t& other) const;

    /**
     * @brief Inequality operator.
     * Checks if two 128-bit integers are not equal.
     * @param other The other 128-bit integer to compare.
     * @return True if the two 128-bit integers are not equal, false otherwise.
     */
    bool operator!=(const uint128_t& other) const;

    /**
     * @brief Inequality operator.
     * Checks if a 128-bit integer and a 64-bit integer have diferent values.
     * @param other The 64-bit integer to compare.
     * @return True if the integers have diferent values, false otherwise.
     */
    bool operator!=(const uint64_t& other) const;

    /**
     * @brief Greater than operator.
     * Checks if this 128-bit integer is greater than another integer.
     * @param other The other 128-bit integer to compare.
     * @return True if this 128-bit integer is greater than the other integer, false otherwise.
     */
    bool operator>(const uint128_t& other) const;

    /**
     * @brief Greater than operator.
     * Checks if this 128-bit integer is greater than a 64-bit integer.
     * @param other The 64-bit integer to compare.
     * @return True if this 128-bit integer is greater than the other integer, false otherwise.
     */
    bool operator>(const uint64_t& other) const;

    /**
     * @brief Less than operator.
     * Checks if this 128-bit integer is less than another integer.
     * @param other The other 128-bit integer to compare.
     * @return True if this 128-bit integer is less than the other integer, false otherwise.
     */
    bool operator<(const uint128_t& other) const;

    /**
     * @brief Less than operator.
     * Checks if this 128-bit integer is less than a 64-bit integer.
     * @param other The 64-bit integer to compare.
     * @return True if this 128-bit integer is less than the other integer, false otherwise.
     */
    bool operator<(const uint64_t& other) const;

    /**
     * @brief Greater than or equal to operator.
     * Checks if this 128-bit integer is greater than or equal to another integer.
     * @param other The other 128-bit integer to compare.
     * @return True if this 128-bit integer is greater than or equal to the other integer, false otherwise.
     */
    bool operator>=(const uint128_t& other) const;

    /**
     * @brief Greater than or equal to operator.
     * Checks if this 128-bit integer is greater than or equal to a 64-bit integer.
     * @param other The 64-bit integer to compare.
     * @return True if this 128-bit integer is greater than or equal to the other integer, false otherwise.
     */
    bool operator>=(const uint64_t& other) const;

    /**
     * @brief Less than or equal to operator.
     * Checks if this 128-bit integer is less than or equal to another integer.
     * @param other The other 128-bit integer to compare.
     * @return True if this 128-bit integer is less than or equal to the other integer, false otherwise.
     */
    bool operator<=(const uint128_t& other) const;

    /**
     * @brief Less than or equal to operator.
     * Checks if this 128-bit integer is less than or equal to a 64-bit integer.
     * @param other The 64-bit integer to compare.
     * @return True if this 128-bit integer is less than or equal to the other integer, false otherwise.
     */
    bool operator<=(const uint64_t& other) const;

    /**
     * @brief Assignment operator.
     * Assigns the value of another 128-bit integer to this integer.
     * @param other The other 128-bit integer to assign.
     * @return A reference to this 128-bit integer after assignment.
     */
    uint128_t& operator=(const uint128_t& other);

    /**
     * @brief Assignment operator.
     * Assigns the value of a 64-bit integer to this integer.
     * @param other The 64-bit integer to assign.
     * @return A reference to this 128-bit integer after assignment.
     */
    uint128_t& operator=(const uint64_t& other);

    /**
     * @brief Left shift assignment operator.
     * Shifts the bits of the 128-bit integer to the left by a specified number of positions and assigns the result to this integer.
     * @param positions The number of positions to shift the bits to the left.
     * @return A reference to this 128-bit integer after the left shift assignment operation.
     */
    uint128_t& operator<<=(const int positions);

    /**
     * @brief Right shift assignment operator.
     * Shifts the bits of the 128-bit integer to the right by a specified number of positions and assigns the result to this integer.
     * @param positions The number of positions to shift the bits to the right.
     * @return A reference to this 128-bit integer after the right shift assignment operation.
     */
    uint128_t& operator>>=(const int positions);

    /**
     * @brief Bitwise AND assignment operator.
     * Performs a bitwise AND operation between the current 128-bit integer and another 128-bit integer and assigns the result to the current integer.
     * @param other The other 128-bit integer to perform the AND operation with.
     * @return A reference to the current 128-bit integer after the AND assignment.
     */
    uint128_t& operator&=(const uint128_t& other);

    /**
     * @brief Bitwise AND assignment operator.
     * Performs a bitwise AND operation between the current 128-bit integer and a 64-bit integer and assigns the result to the current integer.
     * @param other The 64-bit integer to perform the AND operation with.
     * @return A reference to the current 128-bit integer after the AND assignment.
     */
    uint128_t& operator&=(const uint64_t& other);

    /**
     * @brief Bitwise OR assignment operator.
     * Performs a bitwise OR operation between the current 128-bit integer and another 128-bit integer and assigns the result to the current integer.
     * @param other The other 128-bit integer to perform the OR operation with.
     * @return A reference to the current 128-bit integer after the OR assignment.
     */
    uint128_t& operator|=(const uint128_t& other);

    /**
     * @brief Bitwise OR assignment operator.
     * Performs a bitwise OR operation between the current 128-bit integer and a 64-bit integer and assigns the result to the current integer.
     * @param other The 64-bit integer to perform the OR operation with.
     * @return A reference to the current 128-bit integer after the OR assignment.
     */
    uint128_t& operator|=(const uint64_t& other);

    /**
     * @brief Bitwise XOR assignment operator.
     * Performs a bitwise XOR operation between the current 128-bit integer and another 128-bit integer and assigns the result to the current integer.
     * @param other The other 128-bit integer to perform the XOR operation with.
     * @return A reference to the current 128-bit integer after the XOR assignment.
     */
    uint128_t& operator^=(const uint128_t& other);

    /**
     * @brief Bitwise XOR assignment operator.
     * Performs a bitwise XOR operation between the current 128-bit integer and a 64-bit integer and assigns the result to the current integer.
     * @param other The 64-bit integer to perform the XOR operation with.
     * @return A reference to the current 128-bit integer after the XOR assignment.
     */
    uint128_t& operator^=(const uint64_t& other);

    /**
     * @brief Left shift operator.
     * Shifts the bits of the 128-bit integer to the left by a specified number of positions.
     * @param positions The number of positions to shift the bits to the left.
     * @return The 128-bit integer after the left shift operation.
     */
    uint128_t operator<<(const int positions) const;

    /**
     * @brief Right shift operator.
     * Shifts the bits of the 128-bit integer to the right by a specified number of positions.
     * @param positions The number of positions to shift the bits to the right.
     * @return The 128-bit integer after the right shift operation.
     */
    uint128_t operator>>(const int positions) const;

    /**
     * @brief Bitwise AND operator.
     * Performs a bitwise AND operation between two 128-bit integers.
     * @param other The other 128-bit integer to perform the AND operation with.
     * @return The result of the bitwise AND operation.
     */
    uint128_t operator&(const uint128_t& other) const;

    /**
     * @brief Bitwise AND operator.
     * Performs a bitwise AND operation between the current 128-bit integer and a 64-bit integer.
     * @param other The 64-bit integer to perform the AND operation with.
     * @return The result of the bitwise AND operation.
     */
    uint128_t operator&(const uint64_t& other) const;

    /**
     * @brief Bitwise OR operator.
     * Performs a bitwise OR operation between two 128-bit integers.
     * @param other The other 128-bit integer to perform the OR operation with.
     * @return The result of the bitwise OR operation.
     */
    uint128_t operator|(const uint128_t& other) const;

    /**
     * @brief Bitwise OR operator.
     * Performs a bitwise OR operation between the current 128-bit integer and a 64-bit integer.
     * @param other The 64-bit integer to perform the OR operation with.
     * @return The result of the bitwise OR operation.
     */
    uint128_t operator|(const uint64_t& other) const;

    /**
     * @brief Bitwise XOR operator.
     * Performs a bitwise XOR operation between two 128-bit integers.
     * @param other The other 128-bit integer to perform the XOR operation with.
     * @return The result of the bitwise XOR operation.
     */
    uint128_t operator^(const uint128_t& other) const;

    /**
     * @brief Bitwise XOR operator.
     * Performs a bitwise XOR operation between the current 128-bit integer and a 64-bit integer.
     * @param other The 64-bit integer to perform the XOR operation with.
     * @return The result of the bitwise XOR operation.
     */
    uint128_t operator^(const uint64_t& other) const;

    /**
     * @brief Bitwise NOT operator.
     * Performs a bitwise NOT operation on a 128-bit integer.
     * @return The result of the bitwise NOT operation.
     */
    uint128_t operator~() const;

    /**
     * @brief Addition assignment operator.
     * Adds another 128-bit integer to this integer and assigns the result to this integer.
     * @param other The other 128-bit integer to add.
     * @return A reference to this 128-bit integer after the addition assignment operation.
     */
    uint128_t& operator+=(const uint128_t& other);

    /**
     * @brief Addition assignment operator.
     * Adds a 64-bit integer to this integer and assigns the result to this integer.
     * @param other The other 64-bit integer to add.
     * @return A reference to this 128-bit integer after the addition assignment operation.
     */
    uint128_t& operator+=(const uint64_t& other);

    /**
     * @brief Subtraction assignment operator.
     * Subtracts another 128-bit integer from this integer and assigns the result to this integer.
     * @param other The other 128-bit integer to subtract.
     * @return A reference to this 128-bit integer after the subtraction assignment operation.
     */
    uint128_t& operator-=(const uint128_t& other);

    /**
     * @brief Subtraction assignment operator.
     * Subtracts a 64-bit integer to this integer and assigns the result to this integer.
     * @param other The other 64-bit integer to subtract.
     * @return A reference to this 128-bit integer after the subtraction assignment operation.
     */
    uint128_t& operator-=(const uint64_t& other);

    /**
     * @brief Multiplication assignment operator.
     * Multiplies this 128-bit integer by another 128-bit integer and assigns the result to this integer.
     * @param other The other 128-bit integer to multiply by.
     * @return A reference to this 128-bit integer after the multiplication assignment operation.
     */
    uint128_t& operator*=(const uint128_t& other);

    /**
     * @brief Multiplication assignment operator.
     * Multiplies this 128-bit integer by a 64-bit integer and assigns the result to this integer.
     * @param other The 64-bit integer to multiply by.
     * @return A reference to this 128-bit integer after the multiplication assignment operation.
     */
    uint128_t& operator*=(const uint64_t &other);

    /**
     * @brief Division assignment operator.
     * Divides this 128-bit integer by another 128-bit integer and assigns the result to this integer.
     * @param other The other 128-bit integer to divide by.
     * @return A reference to this 128-bit integer after the division assignment operation.
     */
    uint128_t& operator/=(const uint128_t& other);

    /**
     * @brief Division assignment operator.
     * Divides this 128-bit integer by a 64-bit integer and assigns the result to this integer.
     * @param other The 64-bit integer to divide by.
     * @return A reference to this 128-bit integer after the division assignment operation.
     */
    uint128_t& operator/=(const uint64_t& other);

    /**
     * @brief Modulo assignment operator.
     * Calculates the modulo (remainder) of dividing this 128-bit integer by another 128-bit integer and assigns the result to this integer.
     * @param other The other 128-bit integer to divide by.
     * @return A reference to this 128-bit integer after the modulo assignment operation.
     */
    uint128_t& operator%=(const uint128_t& other);

    /**
     * @brief Modulo assignment operator.
     * Calculates the modulo (remainder) of dividing this 128-bit integer by a 64-bit integer and assigns the result to this integer.
     * @param other The 64-bit integer to divide by.
     * @return A reference to this 128-bit integer after the modulo assignment operation.
     */
    uint128_t& operator%=(const uint64_t& other);

    /**
     * @brief Addition operator.
     * Adds two 128-bit integers and returns the sum.
     * @param other The other 128-bit integer to be added.
     * @return The sum of the two 128-bit integers.
     */
    uint128_t operator+(const uint128_t& other) const;

    /**
     * @brief Addition operator.
     * Adds a 128-bit integer and a 64-bit integer and returns the sum.
     * Note: This addition is not commutative, so the order should always be
     * uint128_t before uint64_t.
     * @param other The 64-bit integer to be added.
     * @return The sum of the two 128-bit integers.
     */
    uint128_t operator+(const uint64_t& other) const;

    /**
     * @brief Subtraction operator.
     * Subtracts two 128-bit integers and returns the diference.
     * @param other The other 128-bit integer to be subtracted.
     * @return The difence of the two 128-bit integers.
     */
    uint128_t operator-(const uint128_t& other) const;

    /**
     * @brief Subtraction operator.
     * Subtracts a 64-bit integer to a 128-bit integer and returns the diference.
     * Note: This subtraction is not commutative, so the order should always be
     * uint128_t before uint64_t.
     * @param other The 64-bit integer to be subtracted.
     * @return The difence of the two 128-bit integers.
     */
    uint128_t operator-(const uint64_t& other) const;

    /**
     * @brief Multiplication operator.
     * Multiply two 128-bit integers and return the product.
     * @param other The other 128-bit integer to be multiplied.
     * @return The product of the two 128-bit integers.
     */
    uint128_t operator*(const uint128_t& other) const;

    /**
     * @brief Multiplication operator.
     * Multiply a 128-bit integer and a 64-bit integer and return the product.
     * @param other The 64-bit integer to be multiplied.
     * @return The product of the 128-bit integer and the 64-bit integer.
     */
    uint128_t operator*(const uint64_t& other) const;

    /**
     * @brief Division operator.
     * Divide two 128-bit integers and return the result.
     * @param other The other 128-bit integer to be divided by.
     * @return The result of dividing the two 128-bit integers.
     */
    uint128_t operator/(const uint128_t& other) const;

    /**
     * @brief Division operator.
     * Divide a 128-bit integer by a 64-bit integer and return the result.
     * @param other The 64-bit integer to divide the 128-bit integer by.
     * @return The result of dividing the 128-bit integer by the 64-bit integer.
     */
    uint128_t operator/(const uint64_t& other) const;

    /**
     * @brief Modulo operator.
     * Calculates the modulo (remainder) of dividing two 128-bit integers.
     * @param other The other 128-bit integer to divide by.
     * @return The modulo (remainder) of the division operation.
     */
    uint128_t operator%(const uint128_t& other) const;

    /**
     * @brief Modulo operator.
     * Calculates the modulo (remainder) of dividing this 128-bit integer by a 64-bit integer.
     * @param other The 64-bit integer to divide by.
     * @return The modulo (remainder) of the division operation.
     */
    uint128_t operator%(const uint64_t& other) const;

    /**
    * @brief Conversion operator.
    * Converts an instance of uint128_t to a uint64_t.
    * @return The least significant 64 bits of the 128-bit integer.
    */
    operator uint64_t() const;

    /**
     * @brief Insertion operator for the uint128_t class.
     * Allows a uint128_t object to be printed to an output stream.
     * @param os The output stream where the object will be printed.
     * @param value The uint128_t object to be printed.
     * @return The reference to the output stream, allowing chained operations.
     */
    friend std::ostream& operator<<(std::ostream& os, const uint128_t& value);

};

#endif
