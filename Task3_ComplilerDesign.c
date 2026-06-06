#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "double"
};

int isKeyword(char str[]) {
    int n = sizeof(keywords) / sizeof(keywords[0]);

    for(int i = 0; i < n; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/=%<>!";
    for(int i = 0; operators[i] != '\0'; i++) {
        if(ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int j = 0;

    fp = fopen("input.txt", "r");

    if(fp == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while((ch = fgetc(fp)) != EOF) {

        if(isalnum(ch) || ch == '_') {
            buffer[j++] = ch;
        }
        else {
            if(j > 0) {
                buffer[j] = '\0';

                if(isKeyword(buffer))
                    printf("%s --> Keyword\n", buffer);
                else
                    printf("%s --> Identifier\n", buffer);

                j = 0;
            }

            if(isOperator(ch))
                printf("%c --> Operator\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
