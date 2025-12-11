#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_upper() {
    char *text1 = upper("hello");
    int pass1 = text1 && strcmp(text1, "HELLO") == 0;
    printf("test_upper: %s\n", pass1 ? "PASS" : "FAIL");
    free(text1);

    char *text2 = upper("");
    int pass2 = text2 && strcmp(text2, "") == 0;
    printf("test_upper_empty: %s\n", pass2 ? "PASS" : "FAIL");
    free(text2);

    char *text3 = upper(NULL);
    int pass3 = text3 == NULL;
    printf("test_upper_null: %s\n", pass3 ? "PASS" : "FAIL");
}
