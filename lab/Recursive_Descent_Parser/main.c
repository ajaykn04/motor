#include <stdio.h>
#include <string.h>
#include <ctype.h>
// --- Global Variables ---
char input[10];
int i, error;
// --- Function Prototypes ---
void E();
void T();
void Eprime();
void Tprime();
void F();
// --- Main Function ---
int main()
 {
    i = 0;
    error = 0;
    printf("Enter an arithmetic expression   :   "); // Eg: a+a*a
    gets(input); // Note: gets() is unsafe and deprecated.

    E(); // Start the parser

    if (strlen(input) == i && error == 0) {
        printf("\nAccepted..!!!\n");
    } else {
        printf("\nRejected..!!!\n");
    }
    return 0;
}
// --- Grammar Rule Functions ---
// E -> T E'
void E() {
    T();
    Eprime();
}
// E' -> + T E' | ε (epsilon)
void Eprime() {
    if (input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}
// T -> F T'
void T() {
    F();
    Tprime();
}
// T' -> * F T' | ε (epsilon)
void Tprime() {
    if (input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}
// F -> (E) | id
void F() {
    if (isalnum(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1; // Mismatched parenthesis
        }
    } else {
        error = 1; // Invalid character
    }
}
