#include "BinaryConverter.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

std::string BinaryConverter::decimalToBinary(int decimal) {
    if (decimal < 0) throw std::invalid_argument("Negative numbers not supported.");
    if (decimal == 0) return "0";

    std::string binary = "";
    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int BinaryConverter::binaryToDecimal(const std::string& binary) {
    if (!isValidBinary(binary)) throw std::invalid_argument("Invalid binary string.");
    int decimal = 0;
    for (size_t i = 0; i < binary.size(); ++i)
        if (binary[binary.size() - 1 - i] == '1')
            decimal += static_cast<int>(std::pow(2, i));
    return decimal;
}

std::string BinaryConverter::decimalToHex(int decimal) {
    if (decimal < 0) throw std::invalid_argument("Negative numbers not supported.");
    if (decimal == 0) return "0";

    const char digits[] = "0123456789ABCDEF";
    std::string hex = "";
    while (decimal > 0) {
        hex = std::string(1, digits[decimal % 16]) + hex;
        decimal /= 16;
    }
    return hex;
}

std::string BinaryConverter::decimalToOctal(int decimal) {
    if (decimal < 0) throw std::invalid_argument("Negative numbers not supported.");
    if (decimal == 0) return "0";

    std::string octal = "";
    while (decimal > 0) {
        octal = std::to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

int BinaryConverter::hexToDecimal(const std::string& hex) {
    if (!isValidHex(hex)) throw std::invalid_argument("Invalid hex string.");
    int decimal = 0;
    for (char c : hex) {
        decimal *= 16;
        if (c >= '0' && c <= '9') decimal += c - '0';
        else if (c >= 'A' && c <= 'F') decimal += c - 'A' + 10;
        else decimal += c - 'a' + 10;
    }
    return decimal;
}

bool BinaryConverter::isValidBinary(const std::string& binary) {
    return !binary.empty() &&
        std::all_of(binary.begin(), binary.end(), [](char c) { return c == '0' || c == '1'; });
}

bool BinaryConverter::isValidHex(const std::string& hex) {
    return !hex.empty() &&
        std::all_of(hex.begin(), hex.end(), [](char c) {
            return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
        });
}