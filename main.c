#include "header.h"

    struct Avion avions[100] = {
        {1, "aaa", 15, "Disponible", "rtd"},
        {2, "ccc", 19, "Disponible", "arte"},
        {3, "bbb", 6, "Disponible", "awef"},
        {4, "hhh", 15, "Disponible", "wefd"},
        {5, "eeee", 8, "Disponible", "aed"},
    };
    struct Aeroport aeroport = {
        "Sidi Mohammed", {1, 2, 3, 4, 5}, 5
    };

    int planeID= 6;
    int airportI = 0;
    int numberOfPlanesAvilable = 5;



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