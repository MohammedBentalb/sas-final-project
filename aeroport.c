#include "header.h"


void manageAirport(){
    bool berakIt = false;
    int userChoice = -1;
    do
    {
        printf("-------------------------------------------\n");
        printf("bienvenue, vous avez choisi la gestion de l'aeroport \n");
        printf("1.Ajouter un avion.\n");
        printf("2.Supprimer un avion.\n");
        printf("3.Afficher les informations de l'aeroport et de sa flotte.\n");
        printf("4.Rechercher un avion (par son id ou par model).\n");
        printf("5.Tries les avions (par capacite, par modele alphabetique).\n");        
        printf("0.EXIT TO MAIN MENU.\n");       
        printf("-------------------------------------------\n");
        userChoice = acceptUserInput();


         switch (userChoice)
        {
        case 1:
            printf("--->Ajouter un aeroport.\n");
            break;
        case 2:    
            printf("--->Suprimer un aeroport.\n");
            break;
        case 3:
            printf("--->Afficher la list des aeroports.\n");
            break;
        case 4:
            printf("--->Rechercher un aeroport (par son id ou par model).\n");
            break;
        case 5:
            printf("--->Tries les aeroports (par capacite, par modele alphabetique).\n");
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