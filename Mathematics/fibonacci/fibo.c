#include<stdio.h>

int main(int argc, char *argv[]) {
    int limit, no1 = 0, no2 = 1;
    printf("Enter the number of terms :- ");
    scanf("%d", &limit);
    if(limit == 0) 
        return 0;
    else {
        printf("%d\t", no1);
        for(int i = 0; i < limit - 1; i++) {
            no2 = no1 + no2;
            no1 = no2 - no1;
            printf("%d\t", no1);
        }
    }
    return 0;
}