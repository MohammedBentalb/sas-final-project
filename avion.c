#include "header.h"


void managePlane(){
    int userChoice = -1;
    bool berakIt = false;
    do
    {
        printf("-------------------------------------------\n");
        printf("bienvenue, vous avez choisi la gestion des avions \n");
        printf("1.Ajouter un avion.\n");
        printf("2.Modifier un avion.\n");
        printf("3.Supprimer un avion.\n");
        printf("4.Afficher la list des avions.\n");
        printf("5.Rechercher un avion (par son id ou par model).\n");
        printf("6.Tries les avions (par capacite, par modele alphabetique).\n");        
        printf("0.EXIT TO MAIN MENU.\n");        
        printf("-------------------------------------------\n");
        userChoice = acceptUserInput();


        switch (userChoice)
        {
        case 1:
            printf("--->Ajouter un avion.\n");
            addPlane();
            break;
        case 2:
            printf("--->Modifier un avion.\n");
            break;
        case 3:    
            printf("--->Suprimer un avion.\n");
            deletePlane();
            break;
        case 4:
            printf("--->Afficher la list des avions.\n");
            listPlane();
            break;
        case 5:
            printf("--->Rechercher un avion (par son id ou par model).\n");
            searchForPlane();
            break;
        case 6:
            printf("--->Tries les avions (par capacite, par modele alphabetique).\n");
            sortplane();   
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