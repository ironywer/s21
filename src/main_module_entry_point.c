#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"
void output(const int* mas, int document_count, ...);

int main() {
#ifdef PRINT_LOG
    print_log(print_char, Module_load_success_message);
#endif
#ifdef DOCUMENTS
    int* availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output(availability_mask, Documents_count, Documents);
    free(availability_mask);
#endif
    // Output availability for each document....

    return 0;
}

void output(const int* mas, int document_count, ...) {
    va_list format;
    va_start(format, document_count);
    for (int i = 0; i < document_count; i++) {
        printf("%-15s : %s", va_arg(format, char*), (mas[i] == 0) ? "unavailable" : "available");
        if (i != document_count - 1) printf("\n");
    }
    va_end(format);
}