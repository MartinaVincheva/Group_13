/* Напишете функция, която получавa  като параметър две числа, и връща като резултат броя на позициите в битовото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират (тоест броенето да започне от най-старшия вдигнат бит на по-голямото число). */
#include <stdio.h>

int numberDigits(unsigned int, unsigned int);
void decToBin(unsigned int);
int main(void){
    int a, b, status;       
    do{
        printf("Enter a decimal value for A: ");
        status = scanf("%d", &a);
        getchar();
        if (status == 0){
            printf("Invalid decimal. Pls. enter again.\n");
        }   
    } while (status == 0); 
    if(a < 0){
       	a = ~a;
       	a += 1;
    }
    printf("You entered A with absolute value of %d\n", a);
    decToBin(a);
    printf("\n");
    do{
        printf("Enter a decimal value for B: ");
        status = scanf("%d", &b);
        getchar();
        if (status == 0){
            printf("Invalid decimal. Pls. enter again.\n");
        }     
    } while (status == 0);
    if (b < 0){
       	b = ~b;
       	b += 1;
    }
    printf("You entered B with absolute value of %d\n", b);
    decToBin(b);
    printf("\n\nThe sum of the differences between the numbers on bit level is: %d\n\n", numberDigits(a, b));
    return 0;
}
int numberDigits(unsigned int a, unsigned int b){
    int c = a ^ b;
	int n = 0;
	while(c != 0){
		if(c & 1)
			++ n;
		c >>= 1;
   	}
    return n;
}
void decToBin(unsigned int n){
     printf("Binary value is: ");
     unsigned i;
     unsigned iCheck = 31;
     for (i = 1 << iCheck; i > 0; i = i >> 1){
       	(n & i) ? printf("1") : printf("0");
    }
}
