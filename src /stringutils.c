#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringutils.h"

// ----------------- SPLIT -----------------
char **split(const char *text, char delimiter) {
    if (!text) return NULL;

    // Count how many parts we will get
    size_t partCount = 1;
    for (size_t i = 0; text[i]; i++) {
        if (text[i] == delimiter) partCount++;
    }

    // Allocate memory for array of strings
    char **parts = malloc((partCount + 1) * sizeof(char *));
    if (!parts) return NULL;

    for (size_t i = 0; i <= partCount; i++) parts[i] = NULL;

    size_t startIndex = 0;
    size_t currentPart = 0;

    for (size_t i = 0; ; i++) {
        if (text[i] == delimiter || text[i] == '\0') {
            size_t length = i - startIndex;
            parts[currentPart] = malloc(length + 1);
            if (!parts[currentPart]) {
                split_free(parts);
                return NULL;
            }
            strncpy(parts[currentPart], text + startIndex, length);
            parts[currentPart][length] = '\0';
            currentPart++;
            startIndex = i + 1;
        }
        if (text[i] == '\0') break;
    }

    return parts;
}

// ----------------- SPLIT FREE -----------------
void split_free(char **parts) {
    if (!parts) return;
    for (size_t i = 0; parts[i]; i++) free(parts[i]);
    free(parts);
}

// ----------------- JOIN -----------------
char *join(char **strings, const char *separator) {
    if (!strings || !separator) return NULL;

    size_t separatorLen = strlen(separator);
    size_t totalLen = 0;
    size_t count = 0;

    for (size_t i = 0; strings[i]; i++) {
        totalLen += strlen(strings[i]);
        count++;
    }

    if (count == 0) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }

    totalLen += separatorLen * (count - 1);
    char *result = malloc(totalLen + 1);
    if (!result) return NULL;

    char *ptr = result;
    for (size_t i = 0; i < count; i++) {
        size_t len = strlen(strings[i]);
        memcpy(ptr, strings[i], len);
        ptr += len;
        if (i < count - 1) {
            memcpy(ptr, separator, separatorLen);
            ptr += separatorLen;
        }
    }
    *ptr = '\0';

    return result;
}

// ----------------- TRIM -----------------
char *trim(const char *text) {
    if (!text) return NULL;

    // Skip spaces at the beginning
    while (isspace((unsigned char)*text)) text++;

    if (*text == '\0') return strdup(""); // empty string

    // Find end of string without trailing spaces
    const char *end = text + strlen(text) - 1;
    while (end > text && isspace((unsigned char)*end)) end--;

    size_t length = end - text + 1;
    char *result = malloc(length + 1);
    if (!result) return NULL;

    memcpy(result, text, length);
    result[length] = '\0';

    return result;
}

// ----------------- UPPER -----------------
char *upper(const char *text) {
    if (!text) return NULL;

    size_t length = strlen(text);
    char *result = malloc(length + 1);
    if (!result) return NULL;

    for (size_t i = 0; i < length; i++) {
        result[i] = toupper((unsigned char)text[i]);
    }
    result[length] = '\0';

    return result;
}

// ----------------- STRING BUFFER -----------------
string_buffer *sb_create(size_t initialCapacity) {
    if (initialCapacity == 0) initialCapacity = 16;

    string_buffer *buffer = malloc(sizeof(string_buffer));
    if (!buffer) return NULL;

    buffer->data = malloc(initialCapacity);
    if (!buffer->data) {
        free(buffer);
        return NULL;
    }

    buffer->length = 0;
    buffer->capacity = initialCapacity;
    buffer->data[0] = '\0';
    return buffer;
}

int sb_append(string_buffer *buffer, const char *text) {
    if (!buffer || !text) return -1;

    size_t textLen = strlen(text);
    if (buffer->length + textLen + 1 > buffer->capacity) {
        size_t newCapacity = (buffer->length + textLen + 1) * 2;
        char *newData = realloc(buffer->data, newCapacity);
        if (!newData) return -1;
        buffer->data = newData;
        buffer->capacity = newCapacity;
    }

    memcpy(buffer->data + buffer->length, text, textLen + 1);
    buffer->length += textLen;
    return 0;
}

void sb_free(string_buffer *buffer) {
    if (!buffer) return;
    free(buffer->data);
    free(buffer);
}
