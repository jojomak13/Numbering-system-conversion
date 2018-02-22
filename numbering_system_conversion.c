/**
 ** Coded By: Joeseph Makram
 ** @20/2/2018
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"


int anyToDec(char*, int);
int isHexa(char);
char isHexa2();
int decToAny();

int main()
{
    printf("=======================================================================================\n");
    printf("\t 1. Decimal To Binary | 2. Decimal To Octal | 3. Decimal To Hexa\n");
    printf("\t 4. Binary To Decimal | 5. Binary To Octal  | 6. Binary To Hexa\n");
    printf("\t 7. Octal To Decimal  | 8. Octal To Binary  | 9. Octal To Hexa\n");
    printf("\t 10. Hexa To Decimal  | 11. Hexa To Binary  | 12. Hexa To Octal \n");
    printf("=======================================================================================\n");

    printf("Enter Your Conversion type: ");
    int op = get_int();
    char *number2 = 0;
    int number = 0;

    switch(op)
    {
        /* Start First Case */
        case 1:
            printf("Enter Your Decimal Number: ");
            number = get_int();

            printf("Your Binary Number Is: ");
            decToAny(number, 2);
        break;
        /* End First Case */

        /* Start Second Case */
        case 2:
            printf("Enter Your Decimal Number: ");
            number = get_int();

            printf("Your Octal Number Is: ");
            decToAny(number, 8);
        break;
        /* End Second Case */

        /* Start Third Case */
        case 3:
            printf("Enter Your Decimal Number: ");
            number = get_int();

            printf("Your Hexa Number Is: ");
            decToAny(number, 16);
        break;
        /* End Third Case */

        /* Start 4th Case */
        case 4:
            printf("Enter Your Binary Number: ");
            number2 = get_string();

            printf("Your Decimal Number Is: %i\n", anyToDec(number2, 2));
        break;
        /* End 4th Case */

        /* Start 5th Case */
        case 5:
            printf("Enter Your Binary Number: ");
            number2 = get_string();

            printf("Your Octal Number Is: ");
            number = anyToDec(number2, 2);
            decToAny(number, 8);
        break;
        /* End 5th Case */

        /* Start 6th Case */
        case 6:
            printf("Enter Your Binary Number: ");
            number2 = get_string();

            printf("Your Hexa Number Is: ");
            number = anyToDec(number2, 2);
            decToAny(number, 16);
        break;
        /* End 6th Case */

        /* Start 7th Case */
        case 7:
            printf("Enter Your Octal Number: ");
            number2 = get_string();

            printf("Your Decimal Number Is: %i\n", anyToDec(number2, 8));
        break;
        /* End 7th Case */

        /* Start 8th Case */
        case 8:
            printf("Enter Your Octal Number: ");
            number2 = get_string();

            printf("Your Binary Number Is: ");
            number = anyToDec(number2, 8);
            decToAny(number, 2);
        break;
        /* End 8th Case */

        /* Start 9th Case */
        case 9:
            printf("Enter Your Octal Number: ");
            number2 = get_string();

            printf("Your Hexa Number Is: ");
            number = anyToDec(number2, 8);
            decToAny(number, 16);
        break;
        /* End 9th Case */

        /* Start 10th Case */
        case 10:
            printf("Enter Your Hexa Number: ");
            number2 = get_string();

            printf("Your Decimal Number Is: %d\n", anyToDec(number2, 16));
        break;
        /* End 10th Case */

        /* Start 11th Case */
        case 11:
            printf("Enter Your Hexa Number: ");
            number2 = get_string();

             printf("Your Binary Number Is: ");
             number = anyToDec(number2, 16);
             decToAny(number, 2);
        break;
        /* End 11th Case */

        /* Start 12th Case */
        case 12:
            printf("Enter Your Hexa Number: ");
            number2 = get_string();

             printf("Your Octal Number Is: ");
             number = anyToDec(number2, 16);
             decToAny(number, 8);
        break;
        /* End 12th Case */

    }



    return 0;
}


int decToAny(dec_num, base){
    int counter = 0;

    int result[1000];

    while(dec_num >= base)
    {
        result[counter] = (dec_num % base);
        counter ++;

        if((dec_num % base) == 0){
            dec_num = dec_num / base;
        } else {
            dec_num = (dec_num - (dec_num % base)) / base;
        }

    }
    result[counter] = (dec_num % base);
    counter ++;

    int j;
    for (j = counter - 1; j >= 0; j--){
        if(result[j] > 9){
            printf("%c", isHexa2(result[j]));
        }else{
            printf("%i", result[j]);
        }
    }
    printf("\n");
    return 0;
}


int anyToDec(char *hex, int base){
    const int len = strlen(hex) - 1;
    int power = 1;
    int dec = 0;

    int i;
    for(i = len; i >= 0; i--){
        dec += isHexa(hex[i]) * power;
        power *= base;
    }
    return dec;
}

int isHexa(char c){
    if(isalpha(c)){
        return toupper(c) - 'A' + 10;
    }
    return c - '0';
}

char isHexa2(int num){

    char result = 0;

    if(num == 10){
        result = 'A';
    } else if(num == 11){
        result = 'B';
    } else if(num == 12){
        result = 'C';
    } else if (num == 13){
        result = 'D';
    } else if(num == 14){
        result = 'E';
    } else if(num == 15){
        result = 'F';
    }

    return result;
}