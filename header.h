#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>



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
extern struct Aeroport aeroport[100];
extern int planeID;
extern int airpotID;


/*helpers*/
int acceptUserInput();
void clearInput();



/*primary functions*/
void managePlane();
void addPlane();
void listPlane();


void manageAirport();


#endif 