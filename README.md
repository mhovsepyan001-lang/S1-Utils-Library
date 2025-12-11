# S1-StringUtils-Library

A simple C library for common string operations.

## Functions

| Function | Description |
|----------|-------------|
| `split(str, delimiter)` | Split string into array |
| `split_free(result)` | Free split result |
| `join(strings, separator)` | Join strings into one |
| `trim(str)` | Remove leading/trailing whitespace |
| `upper(str)` | Convert to uppercase |
| `sb_create(capacity)` | Create string buffer |
| `sb_append(sb, str)` | Append to buffer |
| `sb_free(sb)` | Free buffer |

## Requirements

- GCC compiler
- Linux/WSL or Windows with MinGW

## Build

```bash
# Compile demo
gcc -Iinclude src/stringutils.c demo.c -o demo

# Compile tests
gcc -Iinclude src/stringutils.c tests/test_runner.c tests/test_split.c tests/test_trim.c tests/test_upper.c -o test_runner
```

## Run

```bash
# Run interactive demo
./demo

# Run tests
./test_runner
```

## Demo Output

```
=== StringUtils Demo ===

1. SPLIT TEST
   Enter a string (e.g. apple,banana,cherry): apple,banana,cherry
   Enter delimiter (e.g. ,): ,
   Result:
      [0]: apple
      [1]: banana
      [2]: cherry

2. TRIM TEST
   Enter a string with spaces:    hello   
   Before: "   hello   "
   After:  "hello"

3. UPPER TEST
   Enter a string: hello
   Before: hello
   After:  HELLO

4. JOIN TEST
   Joining: [one, two, three]
   Enter separator: -
   Result: one-two-three

5. STRING BUFFER TEST
   Enter strings to append (empty line to stop):
   [1] Append: Hello
       Buffer: "Hello" (length: 5)
   [2] Append: World
       Buffer: "HelloWorld" (length: 10)
   Final result: "HelloWorld"

=== Done ===
```

## Usage Example

```c
#include "stringutils.h"

int main() {
    // Split
    char **parts = split("a,b,c", ',');
    split_free(parts);

    // Join
    char *arr[] = {"one", "two", NULL};
    char *joined = join(arr, "-");
    free(joined);

    // Trim
    char *trimmed = trim("  hello  ");
    free(trimmed);

    // Upper
    char *up = upper("hello");
    free(up);

    // String Buffer
    string_buffer *sb = sb_create(16);
    sb_append(sb, "Hello");
    sb_append(sb, "World");
    sb_free(sb);

    return 0;
}
```

## Project Structure

```
S1-StringUtils-Library/
├── include/
│   └── stringutils.h
├── src/
│   └── stringutils.c
├── tests/
│   ├── test_runner.c
│   ├── test_split.c
│   ├── test_trim.c
│   └── test_upper.c
├── examples/
│   └── main.c
├── demo.c
├── Makefile
└── README.md
```

## License

MIT
