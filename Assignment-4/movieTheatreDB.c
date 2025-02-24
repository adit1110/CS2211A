/*Author: Adit Bhimani
  Student Number: 251289237
  Program Description: This program is basically a database of films, to which you can add and update films*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constant definitions for array sizes and max movie details
#define maxMovieCharacters 100
#define maxMovieGenre 25
#define maxMovieCount 100

typedef struct // structure that represents a movie and it's details
{
    int movieCode;
    char movieName[maxMovieCharacters];
    char movieGenre[maxMovieGenre];
    float movieRating;
} Movie;

// Global array of movies and a counter to track the current number of movies added
Movie movies[maxMovieCount];
int currentCount = 0;

// function definitions
int movieSearchbyCode(int code);
void movieInsert();
void movieSearch();
void movieUpdate();
void moviePrint();

int main() // main bulk of the program
{
    char UserCommand;

    // welcome message
    printf("********************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("********************\n");

    do // do loop for user input
    {
        printf("\nEnter your operation code: ");
        scanf(" %c", &UserCommand);

        switch (UserCommand) // switch statement for user input
        {
        case 'i':
            movieInsert(); // calls the function to insert a movie
            break;
        case 's':
            movieSearch(); // calls the function to search for a movie
            break;
        case 'u':
            movieUpdate(); // calls the function to update a movie
            break;
        case 'p':
            moviePrint(); // calls the function to print the movies
            break;
        case 'q':
            break; // breaks the loop
        default:
            printf("Your user command is invalid, please try again.\n"); // error message for invalid user input
            break;
        }
    } while (UserCommand != 'q');

    return 0;
}

int movieSearchbyCode(int movieCode) // function to search for a movie by code
{
    // loop through the list of movies
    for (int i = 0; i < currentCount; i++)
    {
        if (movies[i].movieCode == movieCode)
        {
            return i; // if the movie code is found, return the index
        }
    }
    return -1; // if the movie code is not found, return -1
}

void movieInsert() // function to insert a movie
{
    if (currentCount >= maxMovieCount) 
    {
        printf("The database is full.\n"); // error message for when the database is full
        return;
    }

    Movie newMovieEntry;
    printf("\tEnter movie code: "); // prompts the user to enter the movie code
    scanf("%d", &newMovieEntry.movieCode); 

    if (movieSearchbyCode(newMovieEntry.movieCode) != -1 || newMovieEntry.movieCode < 0)
    {
        printf("The movie you entered already exists.\n"); // error message for when the movie already exists
        return;
    }

    getchar(); // To consume the newline after scanf
    printf("\tEnter movie name: "); // prompts the user to enter the movie name
    fgets(newMovieEntry.movieName, maxMovieCharacters, stdin); 
    strtok(newMovieEntry.movieName, "\n"); // Remove newline character

    printf("\tEnter movie genre: "); // prompts the user to enter the movie genre
    fgets(newMovieEntry.movieGenre, maxMovieGenre, stdin);
    strtok(newMovieEntry.movieGenre, "\n"); // Remove newline character

    printf("\tEnter movie rating: "); // prompts the user to enter the movie rating
    scanf("%f", &newMovieEntry.movieRating);
    if (newMovieEntry.movieRating < 0.0 || newMovieEntry.movieRating > 10.0)   
    {
        printf("\tInvalid movie rating.\n"); // error message for when the movie rating is invalid
        return;
    }

    movies[currentCount++] = newMovieEntry; // Add the movie to the array and increment the count
}

void movieSearch() // function to search for a movie
{
    int movieCode;
    printf("\tEnter movie code: "); // prompts the user to enter the movie code
    scanf("%d", &movieCode);

    int index = movieSearchbyCode(movieCode); // calls the function to search for the movie by code
    if (index == -1) // If the movie is not found, return
    {
        printf("Movie not found.\n"); // error message for when the movie is not found
        return;
    }

    Movie entry = movies[index]; // Get the movie details
    printf("Movie Code   Movie Name                     Movie Genre               Movie Rating\n"); // prints the movie details
    printf("%-12d %-30s %-25s %-4.1f\n", entry.movieCode, entry.movieName, entry.movieGenre, entry.movieRating);
}

void movieUpdate() // function to update a movie
{
    int movieCode;
    printf("\tEnter movie code: "); // prompts the user to enter the movie code
    scanf("%d", &movieCode);

    int index = movieSearchbyCode(movieCode); // calls the function to search for the movie by code
    if (index == -1) // If the movie is not found, return
    {
        printf("Movie not found.\n"); // error message for when the movie is not found
        return;
    }

    Movie updated_movie;
    updated_movie.movieCode = movieCode; // Since it's an update, we retain the code

    getchar(); // To consume the newline after scanf
    printf("\tEnter movie name: "); // prompts the user to enter the movie name
    fgets(updated_movie.movieName, maxMovieCharacters, stdin);
    strtok(updated_movie.movieName, "\n"); // Remove newline character

    printf("\tEnter movie genre: "); // prompts the user to enter the movie genre
    fgets(updated_movie.movieGenre, maxMovieGenre, stdin);
    strtok(updated_movie.movieGenre, "\n"); // Remove newline character

    printf("\tEnter movie movie rating: "); // prompts the user to enter the movie rating
    scanf("%f", &updated_movie.movieRating);
    if (updated_movie.movieRating < 0.0 || updated_movie.movieRating > 10.0)
    {
        printf("\tInvalid movie rating.\n"); // error message for when the movie rating is invalid
        return;
    }

    movies[index] = updated_movie; // Update the movie details
}

void moviePrint() // function to print the movies
{
    printf("Movie Code   Movie Name                     Movie Genre               Movie Rating\n"); // prints the movie details
    for (int i = 0; i < currentCount; i++) // loop through the list of movies
    {
        printf("%-12d %-30s %-25s %-4.1f\n", movies[i].movieCode, movies[i].movieName, movies[i].movieGenre, movies[i].movieRating); // prints the movie details
    }
}
