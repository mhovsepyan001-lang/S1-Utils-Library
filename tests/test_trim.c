#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void test_trim() {
    char *text1 = trim("  hello world  ");
    int pass1 = text1 && strcmp(text1, "hello world") == 0;
    printf("test_trim: %s\n", pass1 ? "PASS" : "FAIL");
    free(text1);

    char *text2 = trim("      ");
    int pass2 = text2 && strcmp(text2, "") == 0;
    printf("test_trim_spaces_only: %s\n", pass2 ? "PASS" : "FAIL");
    free(text2);

    char *text3 = trim(NULL);
    int pass3 = text3 == NULL;
    printf("test_trim_null: %s\n", pass3 ? "PASS" : "FAIL");
}
