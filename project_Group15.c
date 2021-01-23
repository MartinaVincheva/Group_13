/* Напишете функция, която получавa  като параметър две числа, и връща като резултат броя на позициите в битовото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират (тоест броенето да започне от най-старшия вдигнат бит на по-голямото число). */
#include <stdio.h>

unsigned int findDif(unsigned int a, unsigned int b);
void decToBin(unsigned int n);

int main(void){

    int a, b;

    printf("\nEnter decimal value for A: ");
    scanf("%d", &a);

    if (a < 0){
        a = ~a;
        a += 1;
    }
    printf("You entered A with absolute value of %d\n", a);
    decToBin(a);


    printf("\n\nEnter decimal value for B: ");
    scanf("%d", &b);

    if (b < 0){
        b = ~b;
        b += 1;
    }
    printf("You entered B with absolute value of %d\n", b);
    decToBin(b);

    printf("\n\nThe sum of the differences between the numbers on bit level is: %d\n\n", findDif(a, b));

    return 0;
}

unsigned int findDif(unsigned int a,unsigned int b){
    unsigned int res = a ^ b;
    unsigned int counter = 0;
    unsigned char cCheck = 1;

    do{
        counter += res & cCheck;
    }while(res>>=1);

    return counter;
}

void decToBin(unsigned int n){

    printf("Binary value is: ");

    unsigned i;
    unsigned iCheck = 31;
    for (i = 1 << iCheck; i > 0; i = i >> 1){
        (n & i) ? printf("1") : printf("0");
    }
}