#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char op;      // Operator
    char arg1[10]; // First operand
    char arg2[10]; // Second operand
    char result[10]; // Result
} Expression;
void inputExpressions(Expression expressions[], int *n);
void eliminateCommonSubexpressions(Expression expressions[], int n);
void displayExpressions(const Expression expressions[], int n);
int main() {
    Expression expressions[10];
    int n = 0;
    inputExpressions(expressions, &n);
    printf("\nOriginal Expressions:\n");
    displayExpressions(expressions, n);
    eliminateCommonSubexpressions(expressions, n);
    printf("\nOptimized Expressions:\n");
    displayExpressions(expressions, n);
    return 0;
}
void inputExpressions(Expression expressions[], int *n) {
    printf("Enter the number of expressions: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Enter expression %d:\n", i + 1);
        printf("Result: ");
        scanf("%s", expressions[i].result);
        printf("Arg1: ");
        scanf("%s", expressions[i].arg1);
        printf("Operator: ");
        scanf(" %c", &expressions[i].op);
        printf("Arg2: ");
        scanf("%s", expressions[i].arg2);
    }
}
void eliminateCommonSubexpressions(Expression expressions[], int n) {
    char temp[10];
    int tempCount = 1;
    int optimized = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (expressions[i].op == expressions[j].op &&
                strcmp(expressions[i].arg1, expressions[j].arg1) == 0 &&
                strcmp(expressions[i].arg2, expressions[j].arg2) == 0) {
                sprintf(temp, "t%d", tempCount++);
                strcpy(expressions[i].result, temp);
                strcpy(expressions[j].arg1, temp);
                strcpy(expressions[j].arg2, "");
                expressions[j].op = '=';
                optimized = 1;
            }
        }
    }
    if (!optimized) {
        printf("\nNo common subexpressions found.\n");
    }
}
void displayExpressions(const Expression expressions[], int n) {
    for (int i = 0; i < n; i++) {
        if (expressions[i].op != '=') {
            printf("%s = %s %c %s\n",
                   expressions[i].result,
                   expressions[i].arg1,
                   expressions[i].op,
                   expressions[i].arg2);
        } else {
            printf("%s = %s\n", expressions[i].result, expressions[i].arg1);
        }
    }
}
