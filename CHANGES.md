# Changes

Standalone extraction from `cpp-projects-portfolio` (folder `binary-converter/`), October 2026.

## Code changes

**None.** All 9 source files (`main.cpp`, `BinaryConverter.h/.cpp`, `BinaryMath.h/.cpp`, `BitwisePlayground.h/.cpp`, `HistoryManager.h/.cpp`) and `LICENSE` are byte-for-byte identical to the originals.

## Verification performed

- Compiled with `g++ -std=c++17 -Wall -Wextra` — exit 0, zero errors, zero warnings.
- Scripted test run covered every menu option:
  - Decimal 42 → Binary `101010`; Binary `101010` → Decimal 42
  - `1010 + 0101 = 1111`; `1010 - 0011 = 111`
  - `1100 & 1010 = 1000`; `1100 | 1010 = 1110`; `1100 ^ 1010 = 0110`
  - Error paths: negative decimal → "Negative numbers not supported."; input `102` as binary → "Invalid binary string." — both return to the menu cleanly.
  - History listed all 7 successful operations in order.

## Not carried over

- `Binary_Converter.sln` / `Binary_Converter.vcxproj` — Visual Studio solution/project files; the program builds directly with g++ (see README).
- The original `Readme.md` was replaced by this repo's `README.md` (same feature list — the original readme's claims were checked against the code and all of them are real).
- The original folder `.gitignore` (a Visual Studio template) was replaced with a minimal one covering the compiled binary.
