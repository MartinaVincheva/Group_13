/*
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв на нощ, Стандартна -120 лв на нощ. Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност за клиентите в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
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
float iTotalWithoutTF;
char *assignedBonusName;
float assignedDiscount = 1.00F;

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

float getTotal()
{
    float priceDisc = iTotalWithoutTF * assignedDiscount;
    return priceDisc * fTouristFee;
}

void calculateTotalWithoutTF()
{
    iTotalWithoutTF = ((iNumOfNights * iNumofLux * fPriceLux) + (iNumOfNights * iNumofStandart * fPriceStandart));
}

void printOrder()
{
    printf("Your offer includes %d Standart rooms, %d Luxury Rooms, "
           "for %d nights for the total price of %.2f lv.\n",
           iNumofStandart, iNumofLux, iNumOfNights, getTotal());
    printf("Assigned discount: %s \n", assignedBonusName);
    printf("In the price there is 6 %% Tourist fee included!\n");
    printf("The offer is valid for 14 days!\n");
    printf("The number od your offer is %d!", rand());
}

int main()
{
    printf("Welcome to \"The MAN`s Hotel\"(Martin Anton Nikolay)!\n");
    printf("How many standart rooms would you like?(120 lv. per room for one night)");
    scanf("%d", &iNumofStandart);
    printf("How many lux rooms would you like?(180 lv. per room for one night)");
    scanf("%d", &iNumofLux);
    printf("How many nights would you stay?");
    scanf("%d", &iNumOfNights);
    calculateTotalWithoutTF();

    if (iNumOfNights >= 5 && iTotalWithoutTF < 700)
    {
        assignedDiscount = fDiscountFifteen;
        assignedBonusName = "15% discount";
        printOrder();
    }
    else if (iTotalWithoutTF >= 700 && iTotalWithoutTF < 1000)
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
    else if (iTotalWithoutTF >= 1000)
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
    return 0;
}