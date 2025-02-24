/* Author: Adit Bhimani
   Student Number: 251289237
   Program Description: This file is the actor.c file, where it handles the actor related stuff */

#include "movieTheaterDB_actor.h" // Include the custom header file for Actor struct

// Define the logic for creating a new actor
Actor *actorCreate(int code, const char *name, int age, const char *imdb_link) {
    // Allocate memory for a new Actor struct
    Actor *new_actor = (Actor *)malloc(sizeof(Actor));
    if (!new_actor) {
        return NULL; // Return NULL if memory allocation fails
    }
    // Initialize the fields of the new Actor struct
    new_actor->code = code;
    strncpy(new_actor->name, name, sizeof(new_actor->name) - 1);
    new_actor->name[sizeof(new_actor->name) - 1] = '\0'; // Ensure null-termination
    new_actor->age = age;
    strncpy(new_actor->imdb_link, imdb_link, sizeof(new_actor->imdb_link) - 1);
    new_actor->imdb_link[sizeof(new_actor->imdb_link) - 1] = '\0'; // Ensure null-termination
    new_actor->next = NULL; // Initialize the 'next' pointer to NULL
    return new_actor;
}

// Define the logic for inserting a new actor at the beginning of the list
void actorInsert(Actor **head, Actor *new_actor) {
    if (!head || !new_actor) {
        return; // Return if the input parameters are invalid
    }
    new_actor->next = *head; // Set the 'next' pointer of the new actor to the current head
    *head = new_actor; // Update the head to point to the new actor
}

// Define the logic for deleting an actor by code
void actorDelete(Actor **head, int code) {
    if (head == NULL || *head == NULL) {
        return; // Return if the list is empty or head is NULL
    }

    Actor *temp = *head, *prev = NULL;

    if (temp != NULL && temp->code == code) {
        *head = temp->next; // Update the head to skip the first actor
        free(temp); // Free the memory of the deleted actor
        return;
    }

    while (temp != NULL && temp->code != code) {
        prev = temp;
        temp = temp->next; // Traverse the list to find the actor to delete
    }

    if (temp == NULL) {
        return; // Return if the actor with the specified code is not found
    }

    prev->next = temp->next; // Update 'next' pointers to skip the actor to be deleted

    free(temp); // Free the memory of the deleted actor
}

// Define the logic for finding an actor by code
Actor *actorFind(Actor *head, int code) {
    Actor *current = head;
    while (current != NULL) {
        if (current->code == code) {
            return current; // Return the found actor
        }
        current = current->next; // Move to the next actor in the list
    }
    return NULL; // Return NULL if the actor with the specified code is not found
}

// Define the logic for printing all actors in the list
void actorPrint(Actor *head) {
    Actor *current = head;
    while (current) {
        printf("Code: %d\n", current->code);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("IMDB Link: %s\n", current->imdb_link);
        printf("\n");
        current = current->next; // Move to the next actor in the list
    }
}

// Define the logic for freeing the memory of the entire actor list
void actorFree(Actor **head) {
    Actor *current = *head;
    Actor *next;

    while (current != NULL) {
        next = current->next;
        free(current); // Free the memory of the current actor
        current = next; // Move to the next actor in the list
    }

    *head = NULL; // Update the head to point to NULL (empty list)
}

// Define the logic for updating an actor's details
void updateActor(Actor *actor) {
    int userCommand;
    char name[51];
    int age;
    char imdb_link[51];

    printf("Actor found!\n");
    printf("Code: %d\n", actor->code);
    printf("Name: %s\n", actor->name);
    printf("Age: %d\n", actor->age);
    printf("IMDB Link: %s\n", actor->imdb_link);
    printf("\n");

    printf("What do you want to update?\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("3. IMDB Link\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &userCommand);

    switch (userCommand) {
        case 1:
            printf("Enter new name: ");
            scanf("%s", name);
            strncpy(actor->name, name, sizeof(actor->name) - 1);
            actor->name[sizeof(actor->name) - 1] = '\0'; // Ensure null-termination
            break;
        case 2:
            printf("Enter new age: ");
            scanf("%d", &age);
            actor->age = age;
            break;
        case 3:
            printf("Enter new IMDB Link: ");
            scanf("%s", imdb_link);
            strncpy(actor->imdb_link, imdb_link, sizeof(actor->imdb_link) - 1);
            actor->imdb_link[sizeof(actor->imdb_link) - 1] = '\0'; // Ensure null-termination
            break;
        case 4:
            printf("Returning to the main menu.\n");
            break;
        default:
            printf("The command is invalid.\n");
            break;
    }
}