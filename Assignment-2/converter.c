/* Author: Adit Bhimani
   Student Number: 251289237
   Program Name: Unit Converter
   
   This program calculates basic conversions from units such as kilograms, pounds, liters, gallons, etc.*/


# include <stdio.h>


int mainMenu() // this function below is the main menu function, which shows the user the main menu input
{
    int userChoice;
    printf("What do you want to do? (enter an number for the appropriate conversion): \n");
    printf("1. Conversion between Kilograms and Pounds\n");
    printf("2. Conversion between Hectares and Acres\n");
    printf("3. Conversion between Litres and Gallons\n");
    printf("4. Conversion between Kilometre and Mile\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    return userChoice;
}

int main()
{

    // main variable declarations

    double oneKiloToPounds = 2.20462;
    double oneHectaresToAcres = 2.47105;
    double oneLiterstoGallons = 0.264172;
    double oneKilometersToMiles = 0.621371;

    double onePoundToKilo = 0.453592;
    double oneAcreToHectare = 0.404686;
    double oneGallonToLiter = 3.78541;
    double oneMiletoKilometer = 1.60934;

    int userInput;

    char kToPCharInput, hToACharInput, lToGCharInput, kToMCharInput;

    float kToPInput, hToAInput, lToGInput, kToMInput;

    double kToPFinalConversion, hToAFinalConversion, lToGFinalConversion, kToMFinalConversion, PToKFinalConversion, ATohFinalConversion, GTolFinalConversion, MTokFinalConversion;
    
        userInput = mainMenu(); // this takes the userInput from the main menu function

        switch (userInput) // this switch function is the main part of the whole program, where it does all of the conversions
        {
        case 1: // if the user chooses 1, the following occurs:
            printf("Which way would you like an conversion? Type K for conversion from Kilograms to Pounds, or P for conversion from Pounds to Kilograms (case-sensitive): "); // the program asks which way they would want an conversion
            scanf("%c", &kToPCharInput);
            scanf("%c", &kToPCharInput); // it stores them here

            printf("Please enter a value: "); // it also asks for a value to be converted
            scanf("%f", &kToPInput); // and is stored here

            if((kToPCharInput == 'K') || (kToPCharInput == 'k')) // if the user enters K or k, it would convert it from kilos to pounds
            {
                kToPFinalConversion = oneKiloToPounds * kToPInput; // conversion formula

                printf("Your conversion is... %.2f",kToPFinalConversion); // final output with the conversion
            }
            else if((kToPCharInput == 'P') || (kToPCharInput == 'p')) // if the user enters P or p, it gets converted from pounds to kilos
            {
                kToPFinalConversion = onePoundToKilo * kToPInput; // conversion formula

                printf("Your conversion is... %.2f",kToPFinalConversion); // final output with the conversion
            }
            break;

        case 2: // if the user enters 2, the following happens:
            printf("Which way would you like an conversion? Type H for conversion from Hectares to Acres, or A for conversion from Acres to Hectares: "); // the program asks which way they would want an conversion
            scanf("%c", &hToACharInput);
            scanf("%c", &hToACharInput); // input is stored here

            printf("Please enter a value: "); // conversion value is asked here
            scanf("%f", &hToAInput); // and stored here

            if((hToACharInput == 'H') || (hToACharInput == 'h')) // if the user inputs H or h, it gets converted from hectares to acres
            {
                hToAFinalConversion = oneHectaresToAcres * hToAInput; // conversion formula

                printf("Your conversion is... %.2f",hToAFinalConversion); // final output with the conversion
            }
            else if((hToACharInput == 'A') || (hToACharInput == 'a')) // if the user inputs A or a, it gets converted from acres to hectares // doesn't work
            {
                hToAFinalConversion = oneAcreToHectare * hToAInput; // conversion formula

                printf("Your conversion is... %.2f",hToAFinalConversion); // final output with the conversion
            }
            break;

        case 3: // if the user enters 3, the following happens:
            printf("Which way would you like an conversion? Type L for conversion from Liters to Gallons, or G for conversion from Gallons to Liters: "); // the program asks which way they would want an conversion
            scanf("%c", &lToGCharInput);
            scanf("%c", &lToGCharInput); // the input gets stored here

            printf("Please enter a value: "); // conversion value is asked here
            scanf("%f", &lToGInput); // and is stored here

            if((lToGCharInput == 'L') || (lToGCharInput == 'l')) // if the user enters L or l, it gets converted from liters to gallons
            {
                lToGFinalConversion = oneLiterstoGallons * lToGInput; // conversion formula

                printf("Your conversion is... %.2f",lToGFinalConversion); // final output with the conversion
            }
            else if((lToGCharInput == 'G') || (lToGCharInput == 'g')) // if the user enters G or g, it gets converted from gallons to liters
            {
                GTolFinalConversion = oneGallonToLiter * lToGInput; // conversion formula

                printf("Your conversion is... %.2f",GTolFinalConversion); // final output with the conversion
            }
            break;

        case 4: // if the user enters 4, the following happens:
            printf("Which way would you like an conversion? Type K for conversion from Kilometers to Miles, or M for conversion from Miles to Kilometers: "); // the program asks which way they would want an conversion
            scanf("%c", &kToMCharInput);
            scanf("%c", &kToMCharInput); // input gets stored here

            printf("Please enter a value: "); // conversion value is asked here
            scanf("%f", &kToMInput); // and is stored here

            if((kToMCharInput == 'K') || (kToMCharInput == 'k')) // if the user enters K or k, it gets converted from kilometers to miles
            {
                kToMFinalConversion = oneKilometersToMiles * kToMInput; // conversion formula

                printf("Your conversion is... %.2f",kToMFinalConversion); // final output with the conversion
            }
            else if((kToMCharInput == 'M') || (kToMCharInput == 'm')) // if the user enters M or m, it gets converted from miles to kilometers
            {
                kToMFinalConversion = oneMiletoKilometer * kToMInput; // conversion formula

                printf("Your conversion is... %.2f",kToMFinalConversion); // final output with the conversion
            }
            break;

        case 5: // if the user enters 5, the following happens:
            printf("You are now quitting the program. \n"); // a quit message is printed
            return 0; // and the program quits
            break;

        default: // otherwise
            printf("This is an invalid choice, please try again.\n"); // a error message gets printed
            mainMenu(); // and it jumps back up to the main menu function
            break;
            
        }  


    
    return 0;

}
