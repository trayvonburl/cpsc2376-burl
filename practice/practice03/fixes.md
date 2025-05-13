# Fixes for practice03.cpp

## Function: sumRange
**Bug**: Loop ends at `i < end`.
**Fix**: Changed loop to `i <= end`.

## Function: containsNegative
**Bug 1**: Loop runs with `i <= numbers.size()`.
**Fix**: Changed to `i < numbers.size()`.

**Bug 2**: Condition checks `> 0` instead of `< 0`.
**Fix**: Changed to `if (numbers[i] < 0)`.

## Function: findMax
**Bug 1**: Returns 0 on empty input, which may be misleading.
**Fix**: Returns `INT_MIN` for clarity.

**Bug 2**: (`i <= numbers.size()`).
**Fix**: Changed to `i < numbers.size()`.

**Bug 3**: Uses `>=` unnecessarily.
**Fix**: Replaced with `>` for stricter comparison.