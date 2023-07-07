#include "documentation_module.h"

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list factor;  // указатель на необязательный параметр
    va_start(factor, document_count);  // устанавливаем указатель
    int* mas = malloc(sizeof(int) * document_count);
    for (int i = 0; i < document_count; i++) {
        mas[i] = validate(va_arg(factor, char*));
    }
    va_end(factor);
    return mas;
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
