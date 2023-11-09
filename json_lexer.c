#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Add lists later
typedef enum _json_token_type {
    string,
    number,
    comma,
    colon,
    lcurly,
    rcurly,
} json_token_type;

typedef void *any_t;

typedef struct _json_token {
    json_token_type token;
    char item[50];
} json_token;

json_token* make_string(char str[]) {
    json_token* t = malloc(sizeof(json_token));
    t->token = string;
    strcpy(str, t->item);
    return t;
}

json_token* make_number(float num) {
    json_token* t = malloc(sizeof(json_token));
    t->token = number;
    snprintf(t->item, 50, "%f", num); 
    return t;
}

char* token_repr(json_token* token) {
    char* out;
    switch (token->token) {
        case string: sprintf(out, "\"%s\"", token->item);
        case number: sprintf(out, "%s", token->item);
        default: sprintf(out, "Unknown");
    }
    return out;
}

int main() {
    json_token* token_stream[] = {
        make_string("key"),
        make_number(999),
    };

    int i;
    for (i = 0; i < sizeof(token_stream); i++) {
        char* out = token_repr(token_stream[i]);
        printf("%s", out);
    }

    return 0;
}
