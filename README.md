# Binary Converter Toolkit

A menu-driven C++ console program for working in binary: convert between decimal and binary, convert decimal to hexadecimal and octal, add and subtract binary numbers, run bitwise AND / OR / XOR, and review a history of everything you've done in the session.

Originally part of a C++ projects portfolio; it now lives in its own repository. The code is unchanged from the original — see `CHANGES.md`.

## Features (from the menu)

1. **Decimal to Binary** — enter a non-negative decimal number
2. **Binary to Decimal** — enter a binary string (validated: only `0`s and `1`s)
3. **Binary Add** — sum of two binary numbers
4. **Binary Subtract** — difference of two binary numbers (rejects a negative result)
5. **Bitwise AND** — operands are padded to equal length first
6. **Bitwise OR**
7. **Bitwise XOR**
8. **Show History** — every successful operation this session, in order
9. **Decimal to Hex** — uppercase hex digits (e.g. 255 → `FF`)
10. **Decimal to Octal** — (e.g. 64 → `100`)
11. **Exit**

Invalid input (negative decimal, non-binary characters, subtraction that would go negative) prints an error and returns to the menu instead of crashing.

## Tech

- C++17, standard library only — no external dependencies

## Build

```bash
g++ -std=c++17 -Wall -Wextra -o binary_converter main.cpp BinaryConverter.cpp BinaryMath.cpp BitwisePlayground.cpp HistoryManager.cpp
```

## Run

```bash
./binary_converter
```

## Sample output (trimmed from an actual test run)

```
====  Binary Converter Toolkit ====
1. Decimal to Binary
2. Binary to Decimal
3. Binary Add
4. Binary Subtract
5. Bitwise AND
6. Bitwise OR
7. Bitwise XOR
8. Show History
9. Exit
Enter your choice: 1
Decimal number: 42
 Binary: 101010

Enter your choice: 3
Binary 1: 1010
Binary 2: 0101
 Sum: 1111

Enter your choice: 8

 Conversion History:
• Decimal 42 → Binary 101010
• 1010 + 0101 = 1111

Enter your choice: 9
 Exiting Binary Converter. See you again!
```

## Project structure

```
main.cpp                 Menu loop and user input
BinaryConverter.h/.cpp   Decimal ↔ binary conversion and binary-string validation
BinaryMath.h/.cpp        Binary addition and subtraction (built on the converter)
BitwisePlayground.h/.cpp Bitwise AND / OR / XOR with length padding
HistoryManager.h/.cpp    In-session history of operations
LICENSE                  MIT
```

## License

MIT — see `LICENSE`.
