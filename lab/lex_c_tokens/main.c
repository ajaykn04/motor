#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void main() 
{
    FILE *f1;
    char c, str[100];
    int num = 0, i = 0, lineno = 0;

    f1 = fopen("input.txt", "r");
    printf("Token\t\t\tLexeme\n");

    while ((c = getc(f1)) != EOF) 
    {
        if (isdigit(c)) 
        {
            num = c - 48;
            c = getc(f1);
            while (isdigit(c)) 
            {
                num = num * 10 + (c - 48);
                c = getc(f1);
            }
            printf("Number \t\t\t %d \n", num);
            ungetc(c, f1);
        }
        else if (isalpha(c)) 
        {
            str[i++] = c;
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$') 
            {
                str[i++] = c;
                c = getc(f1);
            }
            str[i++] = '\0';

            if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||  strcmp("case", str) == 0) 
            {
                printf("Keyword \t\t %s \n", str);
            } 
            else 
            {
                printf("Identifier \t\t %s \n", str);
            }
            ungetc(c, f1);
            i = 0;
        } 
        else if (c == ' ' || c == '\t') 
        {
            printf("\n");
        }
        else if (c == '\n') 
        {
            lineno++;
        } 
        else 
        {
            printf("Special symbol \t\t %c \n", c);
        }
    }

    printf("\nTotal no. of lines are: %d \n", lineno);
    fclose(f1);
}
