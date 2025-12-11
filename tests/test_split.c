#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_split() {
    char **parts = split("a,b,c", ',');
    int pass = parts &&
               strcmp(parts[0], "a") == 0 &&
               strcmp(parts[1], "b") == 0 &&
               strcmp(parts[2], "c") == 0 &&
               parts[3] == NULL;
    printf("test_split: %s\n", pass ? "PASS" : "FAIL");
    split_free(parts);

    // Test empty string
    char **parts2 = split("", ',');
    int pass2 = parts2 && strcmp(parts2[0], "") == 0 && parts2[1] == NULL;
    printf("test_split_empty: %s\n", pass2 ? "PASS" : "FAIL");
    split_free(parts2);

    // Test NULL input
    char **parts3 = split(NULL, ',');
    int pass3 = parts3 == NULL;
    printf("test_split_null: %s\n", pass3 ? "PASS" : "FAIL");
}
