// Automated tests for BinaryConverter (decimal/binary/hex/octal).
// Build from the repo root:
//   g++ -std=c++17 -Wall -Wextra -o test_converter tests/test_converter.cpp BinaryConverter.cpp
// Run: ./test_converter   (exit 0 = all checks passed)

#include <iostream>
#include <string>
#include <stdexcept>
#include "../BinaryConverter.h"

static int g_passed = 0;
static int g_failed = 0;

static void check(const std::string& label, const std::string& got,
                  const std::string& expected) {
    if (got == expected) {
        ++g_passed;
    } else {
        ++g_failed;
        std::cout << "FAIL: " << label << " — got '" << got
                  << "', expected '" << expected << "'\n";
    }
}

static void checkInt(const std::string& label, int got, int expected) {
    if (got == expected) {
        ++g_passed;
    } else {
        ++g_failed;
        std::cout << "FAIL: " << label << " — got " << got
                  << ", expected " << expected << "\n";
    }
}

static void checkBool(const std::string& label, bool got, bool expected) {
    if (got == expected) {
        ++g_passed;
    } else {
        ++g_failed;
        std::cout << "FAIL: " << label << " — got "
                  << (got ? "true" : "false") << ", expected "
                  << (expected ? "true" : "false") << "\n";
    }
}

template <typename F>
static void checkThrows(const std::string& label, F fn) {
    try {
        fn();
        ++g_failed;
        std::cout << "FAIL: " << label << " — no exception thrown\n";
    } catch (const std::invalid_argument&) {
        ++g_passed;
    }
}

int main() {
    // Decimal -> binary
    check("decimalToBinary(42)", BinaryConverter::decimalToBinary(42), "101010");
    check("decimalToBinary(0)", BinaryConverter::decimalToBinary(0), "0");
    check("decimalToBinary(255)", BinaryConverter::decimalToBinary(255), "11111111");

    // Decimal -> hex (uppercase digits, added 2026-10-23)
    check("decimalToHex(255)", BinaryConverter::decimalToHex(255), "FF");
    check("decimalToHex(26)", BinaryConverter::decimalToHex(26), "1A");
    check("decimalToHex(0)", BinaryConverter::decimalToHex(0), "0");

    // Decimal -> octal (added 2026-10-23)
    check("decimalToOctal(64)", BinaryConverter::decimalToOctal(64), "100");
    check("decimalToOctal(8)", BinaryConverter::decimalToOctal(8), "10");
    check("decimalToOctal(0)", BinaryConverter::decimalToOctal(0), "0");

    // Binary -> decimal
    checkInt("binaryToDecimal(101010)", BinaryConverter::binaryToDecimal("101010"), 42);
    checkInt("binaryToDecimal(0)", BinaryConverter::binaryToDecimal("0"), 0);

    // Validation
    checkBool("isValidBinary(1010)", BinaryConverter::isValidBinary("1010"), true);
    checkBool("isValidBinary(102)", BinaryConverter::isValidBinary("102"), false);
    checkBool("isValidBinary(empty)", BinaryConverter::isValidBinary(""), false);

    // Error paths
    checkThrows("decimalToBinary(-1) throws",
                [] { BinaryConverter::decimalToBinary(-1); });
    checkThrows("decimalToHex(-5) throws",
                [] { BinaryConverter::decimalToHex(-5); });
    checkThrows("decimalToOctal(-5) throws",
                [] { BinaryConverter::decimalToOctal(-5); });
    checkThrows("binaryToDecimal(102) throws",
                [] { BinaryConverter::binaryToDecimal("102"); });

    std::cout << g_passed << " passed, " << g_failed << " failed\n";
    return g_failed == 0 ? 0 : 1;
}
