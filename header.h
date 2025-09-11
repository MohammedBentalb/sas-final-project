#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_PLANE_NUMBER 100
#define MAX_AIRPORT_NUMBER 1

struct Avion {
    int idAvion;
    char modele[100];
    int capacite;
    char status[20];
    char dateEntree[8];
};

struct Aeroport {
    char name[100];
    int flotte[100];
    int nbAvion;
};

extern struct Avion avions[100];
extern struct Aeroport aeroport;
extern int numberOfPlanesAvilable;
extern int planeID;
extern int airpotID;



/*helpers*/
int acceptUserInput();
void clearInput();



/*primary functions*/
void managePlane();
void addPlane();
void listPlane();
void deletePlane();
void searchForPlane();
void sortplane();


void manageAirport();


#endif 