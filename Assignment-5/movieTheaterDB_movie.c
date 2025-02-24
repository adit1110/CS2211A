/* Author: Adit Bhimani
   Student Number: 251289237
   Program Description: This file is the movie.c file, where it handles the movie related stuff */

// Include necessary header files
#include "movieTheaterDB_movie.h" // Include the custom header file for Movie struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the logic for creating a new movie
Movie *movieCreate(int code, const char *name, const char *genre, float rating) {
    // Allocate memory for a new Movie struct
    Movie *new_movie = (Movie *)malloc(sizeof(Movie));
    if (!new_movie) {
        return NULL; // Return NULL if memory allocation fails
    }
    // Initialize the fields of the new Movie struct
    new_movie->code = code;
    strcpy(new_movie->name, name);
    strcpy(new_movie->genre, genre);
    new_movie->rating = rating;
    new_movie->next = NULL; // Initialize the 'next' pointer to NULL
    return new_movie;
}

// Define the logic for inserting a new movie at the beginning of the list
void movieInsert(Movie **head, Movie *new_movie) {
    if (!head || !new_movie) {
        return; // Return if the input parameters are invalid
    }
    new_movie->next = *head; // Set the 'next' pointer of the new movie to the current head
    *head = new_movie; // Update the head to point to the new movie
}

// Define the logic for printing all movies in the list
void moviePrint(Movie *head) {
    Movie *current = head;
    while (current) {
        printf("Code: %d\n", current->code);
        printf("Name: %s\n", current->name);
        printf("Genre: %s\n", current->genre);
        printf("Rating: %.1f\n", current->rating);
        printf("\n");
        current = current->next; // Move to the next movie in the list
    }
}

// Define the logic for deleting a movie by code
void movieDelete(Movie **head, int code) {
    if (head == NULL || *head == NULL) {
        return; // Return if the list is empty or head is NULL
    }

    Movie *temp = *head, *prev = NULL;

    if (temp != NULL && temp->code == code) {
        *head = temp->next; // Update the head to skip the first movie
        free(temp); // Free the memory of the deleted movie
        return;
    }

    while (temp != NULL && temp->code != code) {
        prev = temp;
        temp = temp->next; // Traverse the list to find the movie to delete
    }

    if (temp == NULL) {
        return; // Return if the movie with the specified code is not found
    }

    prev->next = temp->next; // Update 'next' pointers to skip the movie to be deleted

    free(temp); // Free the memory of the deleted movie
}

// Define the logic for finding a movie by code
Movie *movieFind(Movie *head, int code) {
    Movie *current = head;
    while (current) {
        if (current->code == code) {
            return current; // Return the found movie
        }
        current = current->next; // Move to the next movie in the list
    }
    return NULL; // Return NULL if the movie with the specified code is not found
}

// Define the logic for freeing the memory of the entire movie list
void movieFree(Movie **head) {
    Movie *current = *head;
    Movie *next;

    while (current != NULL) {
        next = current->next;
        free(current); // Free the memory of the current movie
        current = next; // Move to the next movie in the list
    }

    *head = NULL; // Update the head to point to NULL (empty list)
}

// Define the logic for updating a movie
void updateMovie(Movie **movie_list) {
    int code;
    char name[100], genre[25];
    float rating;
    printf("Enter the code of the movie you want to update: \n");
    scanf("%d", &code);
    Movie *foundMovie = movieFind(*movie_list, code);
    if (foundMovie != NULL) {
        printf("Enter the new details of the movie: \n");
        scanf("%d %s %s %f", &code, name, genre, &rating);
        Movie *updatedMovie = movieCreate(code, name, genre, rating); // Create a new movie with updated details
        movieDelete(movie_list, code); // Delete the existing movie
        movieInsert(movie_list, updatedMovie); // Insert the updated movie
    } else {
        printf("The movie with code %d does not exist.\n", code);
    }
}
