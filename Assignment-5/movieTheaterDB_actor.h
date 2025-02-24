/* Author: Adit Bhimani
   Student Number: 251289237
   Program Description: This file is the actor.h file, where it handles the actor structure related stuff */

// Include guards
#ifndef ACTOR_H
#define ACTOR_H

// library declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the Actor
typedef struct Actor {
    int code;
    char name[51]; // 50 characters + null terminator
    int age;
    char imdb_link[51]; // 50 characters + null terminator
    struct Actor *next;
} Actor;

// Function prototypes for declaration

Actor *actorCreate(int code, const char *name, int age, const char *imdb_link); // Function to create a new actor and return a pointer to it
Actor *newActor(int code, const char *name, int age, const char *imdb_link); // Function to create a new actor and return a pointer to it (alternative naming)
void actorInsert(Actor **head, Actor *new_actor); // Function to insert a new actor at the beginning of the list
void actorDelete(Actor **head, int code); // Function to delete an actor by code
Actor *actorFind(Actor *head, int code); // Function to find an actor by code
void actorPrint(Actor *head); // Function to print all actors in the list
void actorFree(Actor **head); // Function to free the memory of the entire actor list
void updateActor(Actor *head); // Function to update an actor's details


#endif // ACTOR_H
