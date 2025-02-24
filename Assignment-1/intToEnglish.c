/* Author: Adit Bhimani
   Student Number: 251289237
   Program Name: Integer to English
   
   This program converts an integer number that is given by the user, and converts it and outputs it in plain english.*/


#include <stdio.h>

void convertToWords(int num) { // this function converts the number to words
    // these two arrays below hold the words for the units and tens places
    const char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                           "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    // this portion below is the main part of converting the numbers to words
    if (num < 20) {
        printf("%s", units[num]); // if the number is less than 20, then it will obtain it directly from the unit array
    } else {
        printf("%s", tens[num / 10]); // numbers that are above 20 are formed by combining the tens and the units
        if (num % 10) // check if there is a non-zero remainder when dividing the number by 10
            printf("-%s", units[num % 10]); // Print the units place in words using the units array and a hyphen for tens-place words (e.g., twenty-three)
    }
}

int main() { // this function below is the main menu
    int num; // variable declaration

    while (1) {
        printf("Please enter a value (1-999, 0 to quit): "); // user input for number
        scanf("%d", &num); // system intakes value here

        if (num == 0) { // if the number is 0
            printf("Goodbye!\n"); // program quits
            break;
        }

        if (num >= 1 && num <= 999) { // if the number is between 1 and 999
            printf("You entered the number "); // this print statement gets executed
            if (num >= 100) { // if the number is at least 100+
                convertToWords(num / 100); // the hundreds place gets converted to words
                printf(" hundred"); // and hundred gets printed
                if (num % 100) // if there are two remaining digits
                    printf(" and "); // and gets printed
                else
                    printf("\n"); // a new line gets printed to clean it up from the next input prompt if there are no remaining digits
                num %= 100; // and store the remainder after extracting the hundreds
            }
            convertToWords(num); // converts the remaining two digits to words
            printf("\n");
        } else {
            printf("Invalid input. Please enter a value between 1 and 999.\n"); // if the number is invalid, then this error message prints out
        }
    }

    return 0;
}
