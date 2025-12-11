#include <stdio.h>
#include <string.h>
#include "stringutils.h"

int main() {
    char input[256];
    char choice;

    printf("=== StringUtils Demo ===\n\n");

    // SPLIT
    printf("1. SPLIT TEST\n");
    printf("   Enter a string (e.g. apple,banana,cherry): ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("   Enter delimiter (e.g. ,): ");
    char delim = getchar();
    getchar(); // clear newline

    char **parts = split(input, delim);
    printf("   Result:\n");
    for (int i = 0; parts[i]; i++) {
        printf("      [%d]: %s\n", i, parts[i]);
    }
    split_free(parts);

    // TRIM
    printf("\n2. TRIM TEST\n");
    printf("   Enter a string with spaces (e.g.    hello   ): ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *trimmed = trim(input);
    printf("   Before: \"%s\"\n", input);
    printf("   After:  \"%s\"\n", trimmed);
    free(trimmed);

    // UPPER
    printf("\n3. UPPER TEST\n");
    printf("   Enter a string: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *up = upper(input);
    printf("   Before: %s\n", input);
    printf("   After:  %s\n", up);
    free(up);

    // JOIN
    printf("\n4. JOIN TEST\n");
    char *words[] = {"one", "two", "three", NULL};
    printf("   Joining: [one, two, three]\n");
    printf("   Enter separator: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *joined = join(words, input);
    printf("   Result: %s\n", joined);
    free(joined);

    // STRING BUFFER
    printf("\n5. STRING BUFFER TEST\n");
    printf("   Enter strings to append (empty line to stop):\n");
    
    string_buffer *sb = sb_create(16);
    int count = 1;
    
    while (1) {
        printf("   [%d] Append: ", count);
        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = '\0';
        
        if (strlen(input) == 0) break;
        
        sb_append(sb, input);
        printf("       Buffer: \"%s\" (length: %zu)\n", sb->data, sb->length);
        count++;
    }
    
    printf("   Final result: \"%s\"\n", sb->data);
    sb_free(sb);

    printf("\n=== Done ===\n");
    return 0;
}
