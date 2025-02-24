/* Author: Adit Bhimani
   Student Number: 251289237
   Program Description: This file is the main header file, where it handles all of the structure related stuff */

#ifndef MOVIE_THEATRE_DB_H // include guard
#define MOVIE_THEATRE_DB_H 

#include "movieTheaterDB_movie.h" // include the header file for the movie struct
#include "movieTheaterDB_actor.h" // include the header file for the actor struct

// library declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype declaration
char mainMenu();
void movieCommands();
void actorCommands();

#endif