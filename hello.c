#include <stdio.h>

enum json_item {
    lsquirly,
    rsquirly,
    lbrack,
    rbrack,
    quote,
    comma,
    character,
};

void printToken(enum json_item item) {
    switch (item) {
        case lsquirly: 
            printf("lsquirly"); 
            break;
        case rsquirly: 
            printf("rsquirly"); 
            break; 
        case lbrack: 
            printf("lbrack"); 
            break; 
        case rbrack: 
            printf("rbrack"); 
            break;
        case quote: 
            printf("quote"); 
            break;
        case comma: 
            printf("comma"); 
            break;
        case character: 
            printf("character");
            break;
    }
}

enum json_item getToken(char current) {
    switch (current) {
        case '{': return lsquirly;
        case '}': return rsquirly;
        case '[': return lbrack;
        case ']': return rbrack;
        case '"': return quote;
        case ',': return comma;
        default: return character;
    }
}


int main() {
    char myInput[] = "{\"key\": \"value\", \"key2\": \"value2\"}";
    int i;
    for (i = 0; i < sizeof(myInput); i++) {
        enum json_item current = getToken(myInput[i]);
        printToken(current);
        printf("\n\r");
    }

    return 0;
}
