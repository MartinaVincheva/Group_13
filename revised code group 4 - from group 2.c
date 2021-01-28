/*
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв на нощ, 
Стандартна -120 лв на нощ. Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност 
за клиентите в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение1:
▪Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
▪Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15% отстъпка или да получи спа процедура за 100 лв.
▪След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
▪Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
▪20% отстъпка
▪Спа процедура на стойност 200 лв
▪2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран. 
*/

#include <stdio.h>
#include <stdlib.h>
const float fPriceStandart = 120.00F; 
const float fPriceLux = 180.00F;
const float fDiscountFifteen = 0.85F; 
const float fDiscountTwenty = 0.80F;
const float fTouristFee = 1.06F;

int iNumofStandart;
int iNumofLux;
int iNumOfNights;
float fTotalWithoutTF;
char *assignedBonusName;
float assignedDiscount = 1.00F;

int getChoice();
float calculateTotalWithoutTF();
float getTotal();
void printOrder();      /* Декларирахме функциите преди main(), а логиката им оставихме след него */

int iNumOfNightsStandart = 0;
int iNumOfNightsLux = 0;
int standartNights;
int luxuryNights;
float iTotalStandartWithoutTF;
float iTotalLuxWithoutTF;  
int totalStandart = 0;
int totalLuxury = 0;     /* Добавихме тези променливи, за да можем да изпълним логиката която добавихме */


int main()
{
    printf("\nWelcome to \"The MAN`s Hotel\"(Martin Anton Nikolay)!\n");
    printf("We offer standart rooms at price of 120 BGN and luxury rooms at price of 180 BGN.\n"); /* Леко променихме този принт */
    
    /* Добавихме от 55 ред един while цикъл с който да направим менюто по-обширно с повече възможни опции */

    int choice;
    while (1){        
        printf("\nFor standart room press 1,\nfor luxury room press 2,\nto proceed with order press 3,\nto quit order press 4!\n");
        scanf("%d", &choice);
        if (choice == 1){
            printf("\nHow many standart rooms would you like?\n");
            scanf("%d", &iNumofStandart);
            if (iNumofStandart == 0){
                continue;
            }
            printf("\nHow many nights would you stay?\n");
            scanf("%d", &standartNights);
            totalStandart += iNumofStandart;
            iNumOfNightsStandart += standartNights;
            printf("Current price: %.2f\n", calculateTotalWithoutTF());
            printf("If you want to quit the whole reservation, and make new one press 0,\nif you want to quit only this room, and continue reservation press 1\nif the price is okay for you and want to countinue with this room press 2.\n");
            scanf("%d", &choice);
                if (choice == 0){
                    iNumofStandart = 0;
                    iNumofLux = 0;
                    iNumOfNightsStandart = 0;
                    iNumOfNightsLux = 0;
                    continue;
                }
                else if (choice == 1){
                    totalStandart -= iNumofStandart;
                    iNumOfNightsStandart -= standartNights;
                    printf("Current price: %.2f\n", calculateTotalWithoutTF());
                    continue;
                }
                else{
                    continue;
                }
        }

        else if (choice == 2){
            printf("\nHow many luxury rooms would you like?(180 lv. per room for one night)\n");
            scanf("%d", &iNumofLux);
            if (iNumofLux == 0){
                continue;
            }
            printf("\nHow many nights would you stay?\n");
            scanf("%d", &luxuryNights);
            totalLuxury += iNumofLux;
            iNumOfNightsLux += luxuryNights;
            printf("Current price: %.2f\n", calculateTotalWithoutTF());
            printf("If you want to quit the whole reservation, and make new one press 0,\nif you want to quit only this room, and continue reservation press 1\nif the price is okay for you and want to countinue with this room press 2.\n");
            scanf("%d", &choice);
                if (choice == 0){
                    iNumofStandart = 0;
                    iNumofLux = 0;
                    iNumOfNightsStandart = 0;
                    iNumOfNightsLux = 0;
                    continue;
                }
                else if (choice == 1){
                    totalLuxury -= iNumofLux;
                    iNumOfNightsLux -= luxuryNights;
                    printf("Current price: %.2f\n", calculateTotalWithoutTF());
                    continue;
                }
                else{
                    continue;
                }
        }

        else if (choice == 3){
            break;
        }

        else if (choice == 4){
            goto quit;
        }

        else{
            printf("Invalid input! Try again!");
        }
    }  

    iNumOfNights = iNumOfNightsStandart + iNumOfNightsLux; /* Тук с помощта на две от променливите, които ние добавихме, изчисляваме общият брой нощувки */

    if (iNumOfNights >= 5 && fTotalWithoutTF < 700)
    {
        assignedDiscount = fDiscountFifteen;
        assignedBonusName = "15% discount";
        printOrder();
    }
    else if (fTotalWithoutTF >= 700 && fTotalWithoutTF < 1000)
    {
        printf("Because your bill is over 700 lv. you get to choose between two discounts. \n");
        printf("1. 15 %% discounton the bill.(press 1) \n");
        printf("2. Spa procedures for 100lv.(press 2) \n");
        int iChoise = getChoice(2);
        switch (iChoise)
        {
        case 1:
            assignedDiscount = fDiscountFifteen;
            assignedBonusName = "15% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 100lv";
            printOrder();
            break;
        }
    }
    else if (fTotalWithoutTF >= 1000)
    {
        printf("Because your bill is over 1000 lv. you get to choose between three discounts. \n");
        printf("1. 20 %% discounton the bill.(press 1) \n");
        printf("2. Spa procedures for 200lv.(press 2) \n");
        printf("3. Two free diners.(press 3) \n");
        int iChoise = getChoice(3);
        switch (iChoise)
        {
        case 1:
            assignedDiscount = fDiscountTwenty;
            assignedBonusName = "20% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 200 lv.";
            printOrder();
            break;
        case 3:
            assignedBonusName = "Two free diners";
            printOrder();
            break;
        }
    }
    else
    {
        assignedBonusName = "no discounts";
        printOrder();
    }

    quit:
        if (choice == 4)
            printf("You just quit your order! Have a nice day!\n");

    return 0;

}

int getChoice(int n)
{
    int iChoise;
    do
    {
        printf("Please enter number from 1 to %d\n", n);
        scanf("%d", &iChoise);
    } while (iChoise < 1 || iChoise > 3);
    return iChoise;
}

float calculateTotalWithoutTF()
{
    /* Добавихме още логика тук, защото сме добавили възможността за всяка избрана стая 
    да се избира отделно броят нощувки, а не да се подава само вднъж за всички стаи общо */
    iTotalStandartWithoutTF = iNumofStandart * iNumOfNightsStandart * fPriceStandart;
    iTotalLuxWithoutTF = iNumofLux * iNumOfNightsLux * fPriceLux;
    fTotalWithoutTF = iTotalStandartWithoutTF + iTotalLuxWithoutTF;
    return fTotalWithoutTF;
}

float getTotal()
{   
    float priceDisc = fTotalWithoutTF * assignedDiscount;
    return priceDisc * fTouristFee;
}

void printOrder()
{
    /* Променихме малко първият printf според логиката която добавихме */ 
    printf("Your offer includes %d Standart rooms with %d nights and %d Luxury Rooms with %d nights, "
           "for the total price of %.2f lv.\n",
           totalStandart, iNumOfNightsStandart, totalLuxury, iNumOfNightsLux, getTotal());
    printf("Assigned discount: %s \n", assignedBonusName);
    printf("In the price there is 6 %% Tourist fee included!\n");
    printf("The offer is valid for 14 days!\n");
    printf("The number of your offer is %d!\n", rand());
}

/* Обобщение на оптимизацията:
1. Добавихме променливи, които да ни помогнат да изпълним оптимизацията, която сметнахме, че е необходима
2. Самата оптимизация се изразява в разширяване на менюто, сложихме го в безкраен while цикъл,
който дава възможност на клиента да избира неограничен брой пъти стаите които желае и в момента в който е избрал всичко нужно
има опция да продължи напред с изготвянето на офертата. Също така след избора на всяка стая и брой нощувки
програмата извежда ориентировъчна цена (цената е без данък и без евентуални отстъпки) и пита клиента,
дали иска да откаже изцяло поръчката и да продължи с нова, дали иска да откаже само стаята която е избрал последно
или цената го удовлетворява и иска да продължи с резервацията си. Също така в менюто има опция за край на програмата
и отказ от правене на поръчка. При въведен невалиден вход, изкарва съобщение и подкранва потребителят да въведе наново избора си.
След като клиентът избере желаният от него брой стаи и нощувки и от менюто избере да продължи напред с резервацията, програмата
продължава с логиката, която колегите са написали. Изчислява цената, при необходимост предлага отстъпки и накря извежда
крайанта оферта, според изборите които клиентът е направил. */