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

## 2026-10-26 — Automated tests for BinaryConverter

- Added `tests/test_converter.cpp`: 18 checks covering decimal→binary,
  decimal→hex, decimal→octal, binary→decimal, `isValidBinary`, and the
  error paths (negative input and non-binary strings throw
  `std::invalid_argument`). The test file is standalone — it compiles
  against `BinaryConverter.cpp` only and does not change the app build.
- `README.md` gained a Tests section and the project-structure listing.
- Verified: compiled with `g++ -std=c++17 -Wall -Wextra` (zero warnings)
  and the suite printed `18 passed, 0 failed` with exit 0. The main app
  still builds cleanly and its menu is untouched.

## 2026-10-23 — Decimal to hex and octal

- Added `BinaryConverter::decimalToHex` and `BinaryConverter::decimalToOctal`
  (menu options 9 and 10; Exit moved to 11). Both follow the existing rules:
  negative input is rejected with "Negative numbers not supported." and 0
  converts to "0". Successful conversions are recorded in the session history.
- Verified: compiled with `g++ -std=c++17 -Wall -Wextra` (zero warnings).
  Scripted run: 255 → Hex `FF`; 64 → Octal `100`; 0 → `0` in both; -5 →
  error and back to menu; history listed all conversions in order; existing
  decimal→binary conversion unchanged (42 → `101010`).
