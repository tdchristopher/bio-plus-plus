# C++ syntax through biology

```cpp
bpp::DNA dna("ATGC");
// 1  :: 2   3
```

1. `bpp` = **namespace**: groups related definitions.
2. `DNA` = **class**: a blueprint for a type.
3. `dna` = **object variable**: one instance of that type.

Read it: “Create an object named `dna` of class `DNA` from namespace `bpp`.”

- `::` = scope resolution (“find this name inside that scope”).
- `.` = access a member on an object, e.g. `dna.sequence()`.
- `private:` = implementation details hidden from callers.
- `public:` = operations callers can use.
- `std::queue` = waiting line.
- `std::vector` = expandable list.
- `const` = read-only.

## Tiny exercise
Change the initial energy from `25` to `5`. Predict how many times `makeProtein()` succeeds, then compile and run.
