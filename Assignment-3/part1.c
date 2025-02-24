/*Author: Adit Bhimani
  Student Number: 251289237
   Program Description: This program takes integers from the user, puts said integers in the array, and outputs
   them in certain ways.*/

#include <stdio.h> // library declaration


// void function declarations
void arrayPrint(int userArray[], int userNum);
void arrayReverse(int userArray[], int userNum);
void arrayPrintEven(int userArray[], int userNum);
void arraySum(int userArray[], int userNum);
void arraySorted(int userArray[], int userNum);
void arraySwap(int userArray[], int userNum);


void arrayPrint(int userArray[], int userNum) { // this function with the loop, will print the array
    printf("\tYour array is: "); // text for the array
    for (int i = 0; i < userNum; i++) { // for loop that goes through the array
        printf("[%d] = %d, ", i, userArray[i]); // prints the array
    }
    printf("\n"); // new line declaration
}
void arrayReverse(int userArray[], int userNum) { // this function with the loop will print the array in reverse
    printf("\tYour array in reverse is: "); // text for the array in reverse
    for (int i = userNum - 1; i >= 0; i--) { // for loop that goes through the array in reverse
        printf("[%d] = %d, ", i, userArray[i]); // prints the array in reverse
    }
    printf("\n"); // new line declaration
}
void arrayPrintEven(int userArray[], int userNum) { // this function with the loop will print the even numbers in the array
    printf("\tThe even elements in the array is: "); // text for the even numbers in the array
    for (int i = 0; i < userNum; i++) { // for loop that goes through the array
        if(userArray[i] % 2 == 0) { // if statement that checks if the number is even
            printf("[%d] = %d,", i, userArray[i]); // prints the even numbers
        }
    }
    printf("\n\n"); // new line declaration
}
void arraySum(int userArray[], int userNum) { // function that calculates and prints the array sum
    int numSum = 0; // variable declaration for the sum of the array

    for(int i = 0; i < userNum; i++) { // for loop that goes through the array
        numSum+= userArray[i]; // adds the numbers in the array
    }
    printf("\tThe sum of all values in your array is: %d\n", numSum); // prints the sum of the array
}
void arraySorted(int userArray[], int userNum) { // function that sorts the array in ascending order
     int tempArr[userNum]; // temporary array declaration
    for (int i = 0; i < userNum; i++) {  // for loop that goes through the array
        tempArr[i] = userArray[i]; // copies the array into the temporary array
    }

    for (int i = 0; i < userNum - 1; i++) { // for loop that goes through the array
        for (int j = 0; j < userNum - i - 1; j++) { // for loop that goes through the array
            if (tempArr[j] > tempArr[j + 1]) { // if statement that checks if the number is greater than the next number
                int temp = tempArr[j]; // temporary variable declaration
                tempArr[j] = tempArr[j + 1]; // number swap
                tempArr[j + 1] = temp; // number swap
            }
        }
    }

    printf("\tYour array in sorted order is: "); // text for the sorted array
    for (int i = 0; i < userNum; i++) { // for loop that goes through the array
        for (int j = 0; j < userNum; j++) { // for loop that goes through the array
            if (tempArr[i] == userArray[j]) { // if statement that checks if the number in the temporary array is equal to the number in the original array
                printf("[%d] = %d, ", j, userArray[j]); // prints the sorted array
                break;
            }
        }
    }
    printf("\n"); // new line declaration
}
void arraySwap(int userArray[], int userNum) { // function that swaps the first and last element of the array
    printf("\tYour array with the first and last element switched is: "); // text for the array with the first and last element switched

    printf("[%d] = %d, ", userNum - 1, userArray[userNum- 1]); // prints the last element of the array
    for (int i = 1; i < userNum - 1; i++) { // for loop that goes through the array
        printf("[%d] = %d, ", i, userArray[i]); // prints the array
    }
    printf("[%d] = %d, ", 0, userArray[0]); // prints the first element of the array
    printf("\n"); // new line declaration
}

int main() {
    int userNum; // variable declaration for user integer number
    

    printf("Please enter the number of integers to process: "); // user input for integer
    scanf("%d", &userNum);

    while (userNum < 5 || userNum > 12) // while loop that keeps running if the user does not enter a number between 5 and 12
    {
        printf("Please enter a number between 5 and 12: "); // user input for integer if the above condition is met
        scanf("%d", &userNum); // system intake for the user integer
    }

    int bytes = userNum * sizeof(int); // bytes calculation
    printf("\tThere is enough room in your array for %d integers (%d bytes)\n", userNum, bytes); // confirmation message display

    int userArray[userNum]; // array declaration
    printf("Please enter your integers seperated by spaces: "); // user input for the integers
    for (int i = 0; i < userNum; i++) { // for loop that goes through the array
        scanf("%d", &userArray[i]); // scans the array
    }


    // Calling functions below here will print everything out in order

    printf("\nPart 1:\n"); // print line that prints the part number
    arrayPrint(userArray, userNum); // where the information will come from

    printf("\nPart 2:\n"); // print line that prints the part number
    arrayReverse(userArray, userNum); // where the information will come from

    printf("\nPart 3:\n"); // print line that prints the part number
    arrayPrintEven(userArray, userNum); // where the information will come from

    printf("\nPart 4:\n"); // print line that prints the part number
    arraySum(userArray, userNum); // where the information will come from

    printf("\nPart 5:\n"); // print line that prints the part number
    arraySorted(userArray, userNum); // where the information will come from

    printf("\nPart 6:\n"); // print line that prints the part number
    arraySwap(userArray, userNum); // where the information will come from



    return 0;


}
