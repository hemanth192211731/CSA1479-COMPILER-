#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

typedef struct {
    char op;     // Operator
    char arg1[10];  // First argument
    char arg2[10];  // Second argument
    char result[10]; // Result of the operation
} TAC;

// Global variables to store TAC instructions and temporary variables
TAC tac[MAX_EXPR_LEN];
int tempVarCount = 1;
int tacCount = 0;

// Function declarations
void generateTAC(char* expr);
void processOperator(char op, char* left, char* right, char* result);
void printTAC();

int main() {
    char expr[MAX_EXPR_LEN];

    // Input expression
    printf("Enter an arithmetic expression: ");
    fgets(expr, MAX_EXPR_LEN, stdin);
    expr[strcspn(expr, "\n")] = 0; // Remove newline character

    // Generate and print TAC
    generateTAC(expr);
    printTAC();

    return 0;
}

// Generate TAC for a given arithmetic expression
void generateTAC(char* expr) {
    char stack[MAX_EXPR_LEN][10]; // Stack to hold intermediate results
    int stackTop = -1;
    char temp[10];
    char left[10], right[10];
    int i, j;

    // Iterate through each character of the expression
    for (i = 0; i < strlen(expr); i++) {
        if (isalnum(expr[i])) { // If character is an operand (letter or number)
            j = 0;
            while (isalnum(expr[i])) {
                temp[j++] = expr[i++];
            }
            temp[j] = '\0';
            strcpy(stack[++stackTop], temp); // Push operand onto the stack
            i--;
        } else if (strchr("+-*/", expr[i])) { // If character is an operator
            strcpy(right, stack[stackTop--]); // Pop right operand
            strcpy(left, stack[stackTop--]);  // Pop left operand
            sprintf(temp, "t%d", tempVarCount++); // Create temporary variable
            processOperator(expr[i], left, right, temp); // Generate TAC
            strcpy(stack[++stackTop], temp); // Push result back to stack
        }
    }
    if (stackTop >= 0) {
        strcpy(temp, stack[stackTop--]);
        sprintf(tac[tacCount].result, "result");
        sprintf(tac[tacCount].arg1, "%s", temp);
        sprintf(tac[tacCount].op, "=");
        tacCount++;
    }
}
void processOperator(char op, char* left, char* right, char* result) {
    sprintf(tac[tacCount].op, "%c", op);
    strcpy(tac[tacCount].arg1, left);
    strcpy(tac[tacCount].arg2, right);
    strcpy(tac[tacCount].result, result);
    tacCount++;
}
void printTAC() {
    printf("\nThree Address Code:\n");
    for (int i = 0; i < tacCount; i++) {
        printf("%s = %s %s %s\n",
               tac[i].result,
               tac[i].arg1,
               tac[i].op,
               tac[i].arg2);
    }
}
