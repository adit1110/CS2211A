/*Author: Adit Bhimani
  Student Number: 251289237
  Program Description: This file is the movie header file, where it handles the movie structure related stuff */

#ifndef MOVIE_H // include guards
#define MOVIE_H

// library declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie { // struct for the movie
    int code;
    char name[100]; // 99 characters + null terminator
    char genre[25]; // 24 characters + null terminator
    float rating;
    struct Movie *next;
} Movie;

// Function prototypes for naming
Movie *movieCreate(int code, const char *name, const char *genre, float rating);
Movie *newMovie(int code, const char *name, const char *genre, float rating);
void movieInsert(Movie **head, Movie *new_movie);
void movieDelete(Movie **head, int code);
Movie *movieFind(Movie *head, int code);
void moviePrint(Movie *head);
void movieFree(Movie **head);
void updateMovie(Movie **movie_list);

#endif // MOVIE_H
