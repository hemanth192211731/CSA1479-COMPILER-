#include<stdio.h>
#include<string.h>

int main() {
    int n, i, j;
    char a[50][50];
    printf("Enter the number of intermediate codes: ");
    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        printf("Enter the 3-address code %d: ", i + 1);
        fgets(a[i], sizeof(a[i]), stdin);
       
        a[i][strcspn(a[i], "\n")] = 0;
    }

    printf("The generated code is:");
    for (i = 0; i < n; i++) {
        printf("\n mov %c,R%d", a[i][2], i);  
        switch (a[i][3]) {
            case '-':
                printf("\n sub %c,R%d", a[i][4], i);
                break;
            case '+':
                printf("\n add %c,R%d", a[i][4], i);
                break;
            case '*':
                printf("\n mul %c,R%d", a[i][4], i);
                break;
            case '/':
                printf("\n div %c,R%d", a[i][4], i);
                break;
        }
        printf("\n mov R%d,%c", i, a[i][0]);  
    }

    return 0;
}
 
