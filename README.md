# **S1-StringUtils-Library**

This library solves the problem of missing high-level string utilities in the C programming language.
In languages like Python, operations such as splitting, joining, trimming, and modifying strings are built-in and easy to use.
In C, these operations require manual memory management, pointer handling, and careful allocation to avoid leaks or crashes.

**S1-StringUtils-Library provides safe, ready-to-use C implementations** of common string functions, making it easier to perform these operations without rewriting them from scratch.

---

## **Features**

* `split()` – Split a string by a delimiter
* `split_free()` – Free memory allocated by split
* `join()` – Join an array of strings into one
* `trim()` – Remove leading and trailing whitespace
* `upper()` – Convert all characters to uppercase
* `string_buffer` – Dynamic resizable string builder

---

## **Project Structure**

```
S1-StringUtils-Library/
│
├── stringutils.c
├── stringutils.h
├── demo.c
└── README.md
```

---

## **Build Instructions**

### **Compile**

```
gcc stringutils.c demo.c -o demo
```

### **Run**

```
./demo
```

---

## **Demo Example (`demo.c`)**

````markdown
```c
#include <stdio.h>
#include "stringutils.h"

int main() {
    char **tokens = split("apple,banana,orange", ',');
    for (int i = 0; tokens[i]; i++)
        printf("%s\n", tokens[i]);
    split_free(tokens);

    char *arr[] = {"Hello", "World", "C", NULL};
    char *joined = join(arr, " ");
    printf("%s\n", joined);
    free(joined);

    char *trimmed = trim("   Hello World   ");
    printf("%s\n", trimmed);
    free(trimmed);

    char *up = upper("hello");
    printf("%s\n", up);
    free(up);

    string_buffer *sb = sb_create(16);
    sb_append(sb, "Hello ");
    sb_append(sb, "world!");
    printf("%s\n", sb->data);
    sb_free(sb);

    return 0;
}
```
````

---

## **Usage in Another Project**

```
#include "stringutils.h"
gcc main.c stringutils.c -o program
```

---

## **Author**

Meri Hovsepyan
S1 Programming Course — 2025



