#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <stdlib.h>

// ----------------- SPLIT -----------------
// Split a string by a delimiter, returns NULL-terminated array of strings
char **split(const char *text, char delimiter);

// Free the result of split()
void split_free(char **parts);

// ----------------- JOIN -----------------
// Join array of strings with a separator
char *join(char **strings, const char *separator);

// ----------------- TRIM -----------------
// Remove spaces at the beginning and end of a string
char *trim(const char *text);

// ----------------- UPPER -----------------
// Convert a string to uppercase (returns new allocated string)
char *upper(const char *text);

// ----------------- STRING BUFFER -----------------
// Struct for dynamic string buffer
typedef struct {
    char *data;       // pointer to the string data
    size_t length;    // current length of string
    size_t capacity;  // allocated memory capacity
} string_buffer;

// Create a string buffer with initial capacity
string_buffer *sb_create(size_t initialCapacity);

// Append a string to the buffer (0 = success, -1 = failure)
int sb_append(string_buffer *buffer, const char *text);

// Free the memory of string buffer
void sb_free(string_buffer *buffer);

#endif // STRINGUTILS_H
