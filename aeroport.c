#include "header.h"


void manageAirport(){
    bool berakIt = false;
    int userChoice = -1;
    do
    {
        printf("-------------------------------------------\n");
        printf("bienvenue, vous avez choisi la gestion de l'aeroport \n");
        printf("1.Afficher les informations de l'aeroport et de sa flotte.\n");      
        printf("1.Afficher les .\n");      
        printf("0.EXIT TO MAIN MENU.\n");       
        printf("-------------------------------------------\n");
        userChoice = acceptUserInput();


         switch (userChoice)
        {
        case 1:
            printf("--->Afficher les information de l'aeroport.\n");
            listAirportInfo();
            break;
        case 2:
            printf("--->le percentage d'avion disponible.\n");
            calculateCoef();
            break;
        case 0:
            printf("--->EXIT TO MAIN MENU.\n");
            berakIt = true;
            break;
        
        default:
            break;
        }
    } while (!berakIt);
    
}


