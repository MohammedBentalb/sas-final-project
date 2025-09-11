#include "header.h"


struct Avion avions[100] = {0};
struct Aeroport aeroport[100] = {0};
int planeId = 1;
int airportId = 0;


int main(){

    bool breakIt = false;
    int userChoise = -1;

    

    do
    {
        printf("-----------------------------------------------\n");
        printf("                  Beinvenue                     \n");
        printf("1.gestion des Avions.\n");
        printf("2.gestion de l'airoport.\n");
        printf("0.EXIT.");
        printf("-----------------------------------------------\n");
        userChoise = acceptUserInput();

        switch (userChoise)
        {
        case 1:
            managePlane();
            break;
        case 2:
            manageAirport();
            break;
        case 0:
            printf("See U Soon\n");
            breakIt = true;
            break;
        
        default:
            printf("Choix incorect!!!\n");
            break;
        }


    } while (!breakIt);
    
    

    return 0;
}