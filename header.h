#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>



struct Avion {
    int idAvion;
    char model[100];
    int capacite;
    char ststus[20];
    char dateEntree[8];
};

struct Aeroport {
    char name[100];
    int flotte[100];
    int nbAvion;
};

extern struct Avion avions[100];
extern struct Aeroport aeroport[100];



/*helpers*/
int acceptUserInput();
void clearInput();



/*primary functions*/
void gestionAvion();
void gestionAeoport();


#endif 