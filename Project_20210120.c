/* "Напишете функция, която преброява колко думи има в един стринг, който й се подава като параметър." */
#include <stdio.h>

/* Дефинираме две константи. Една за знак и една за буква. */
#define Sign   0
#define Letter 1

/* Създаваме функция която ще използваме, за да можем да прочетем даден текст, въведен от потребителя. */
void getInput(char *str) {
    char c ;

    /* Създаваме цикъл при който потребителя въвежда символи, докато не натисне нов ред. Всеки символ се добавя към стринга. */
    while ((c = getchar()) != '\n') {
        *str++ = c;
    }
    *str ='\0';
}

/* Създаваме функция която ще премине през всички символи в подаден стринг и ще преброи думите. */
unsigned countTheWords(char *str) {
    int state = Sign;
    unsigned WordCounter = 0;

    /* Обхождаме стринга / низа */
    while (*str)
    {    
        /* Проверяваме дали символа е различен от буква. */
        if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '.' || *str == '!' || *str == '?' || *str == ',' || *str == ':' || *str == ';' || *str == '@' || *str == '#' || *str == '$' || *str == '%' || *str == '^' || *str == '&' || *str == '*' || *str == '+' || *str == '=' || *str == '"' ){
            state = Sign;
        } else if (state == Sign) {
            state = Letter;
            ++WordCounter;/* Брояч на думите. */
        }
        ++str; /* Преминаваме на следващият символ. */
    }
    return WordCounter; /* Връщаме брой думи. */
}

/* Нашата main функция в която искаме от потребителя да въведе своя текст и ние му връщаме броя на думите в него. */
int main(void) {
    char str[256];

    printf("Enter your text here:"); 
    getInput(str);
    printf("Numbers of words in \"%s\" : %d", str, countTheWords(str));
    return 0;
}
