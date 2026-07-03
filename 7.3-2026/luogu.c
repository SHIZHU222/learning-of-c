//P1089
#include <stdio.h>

int main() {
    int cash = 0;         
    int saved = 0;         
    int budget;
    for (int month = 1; month <= 12; month++) {
        cash += 300;                          

        scanf("%d", &budget);

        if (cash < budget) {                  
            printf("-%d\n", month);
            return 0;                        
        }

        cash -= budget;                      

        while (cash >= 100) {                
            cash -= 100;
            saved += 100;
        }
    }

    int final = cash + saved * 6 / 5;         
    printf("%d\n", final);

    return 0;