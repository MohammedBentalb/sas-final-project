#include  "header.h"

void addPlane(){

    int userChoice = 0;
    char planeModele[100], planeStatus[100], planeEntranceDate[5];
    char status[][20] = {"Disponible", "En maintenance", "En vole"};
    int userStatusChoice = -1, planeCapacity = 9;
    int i = 0;

    printf("Combier d'avion vous voulez ajoutez: ");
    userChoice = acceptUserInput();

    while(userChoice > 0){
        userStatusChoice = -1;

        printf("-->Donnez le modele de l'avion: ");
        scanf("%[^\n]", planeModele);
        
        printf("-->Quelle est la capacite de l'avion: ");
        planeCapacity = acceptUserInput();
        
        printf("-->Quelle est le status de l'avion: ");
        userStatusChoice = acceptUserInput();        
        
        printf("-->donnez la date d''entree de l'avion: ");
        scanf("%[^\n]", planeEntranceDate);
        
        printf("%s\n", planeModele);
        printf("%s\n", planeEntranceDate);

        printf("\n");

        while(avions[i].modele[0] != '\0'){
            i++;
        }

        avions[i].idAvion = planeID++;
        strcpy(avions[i].modele, planeModele);
        strcpy(avions[i].status, userStatusChoice > 2 || userStatusChoice < 0 ? status[1] : status[userStatusChoice]);
        avions[i].capacite = planeCapacity;
        strcpy(avions[i].dateEntree, planeEntranceDate);
        
        if(userStatusChoice> 3 && userStatusChoice){
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
            printf("VOUS AVEZ ENTRE UN CHOIX INVALIDE POUR LE STATUT, IL A DONC ÉTÉ PARAMÉTRÉ SUR \"EN MAINTENANCE\". VOUS POUVEZ LE MODIFIER PLUS TARD.\n");
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
        }

        userChoice--;
        clearInput();

    }

}

void listPlane(){
    int i = 0, count = 0;
    while(avions[i].modele[0] != '\0'){
        printf("\n");
        printf("\n");
        printf("--------------------------------------------------\n");
        printf("---N: %d\n", i + 1);
        printf("---Le ID de l'Avion: %d\n", avions[i].idAvion);
        printf("---Le modele de l'Avion: %s\n", avions[i].modele);
        printf("---La capacite de l'Avion: %d\n", avions[i].capacite);
        printf("---Le status de l'Avion: %s\n", avions[i].status);
        printf("---La date d'entree de l'Avion: %s\n", avions[i].dateEntree);
        printf("--------------------------------------------------\n");
        i++;
        count++;
    }

    if(count == 0){
        printf("No planes available.\n");
        return;
    }
    printf("La fin de la list.\n");
}

void deletePlane(){
    int i = 0, target = 0;
    bool found = false;

    printf("Donner de l'ID de l'avoin que vouvolez supprimer: ");
    target = acceptUserInput();

    while(i <  MAX_PLANE_NUMBER && avions[i].modele[0] != '\0'){        
        if(avions[i].idAvion == target){
            found = true;
            break;
        }
        i++;
    }

    if(!found){
        printf("L'avion que vous cherchez n'existe pas.\n");
        return;
    }

    for(int j = i; j < MAX_PLANE_NUMBER - 1; j++){
        avions[i] = avions[i + 1];
    }

    printf("L'avion a été supprimé avec succès!!");
}

void searchForPlane(){
    int userChoise = 0;
    printf("Que voulez vous utiliser come un utile de recherche (1.id, 2.modele): ");
    userChoise = acceptUserInput();

    switch (userChoise)
    {
    case 1:
        int i = 0, id = 0;
        printf("Donnez l'ID de l'avion: ");
        id = acceptUserInput();

        while (i < MAX_PLANE_NUMBER && avions[i].idAvion != 0) {
            if(avions[i].idAvion == id){
                printf("-----------------------------\n");
                printf("---N: %d\n", i + 1);
                printf("---Le ID de l'Avion: %d\n", avions[i].idAvion);
                printf("---Le modele de l'Avion: %s\n", avions[i].modele);
                printf("---La capacite de l'Avion: %d\n", avions[i].capacite);
                printf("---Le status de l'Avion: %s\n", avions[i].status);
                printf("---La date d'entree de l'Avion: %s\n", avions[i].dateEntree);
                printf("-----------------------------\n");
                break;
            }
            i++;
        }

        break;
    case 2:
        char modele[100];
        printf("Donnez le model de l'avion: ");
        scanf("%[^\n]", modele);

        while (i < MAX_PLANE_NUMBER && avions[i].modele[0] != '\0') {
            if(strcasecmp(avions[i].modele, modele) == 0){
                printf("-----------------------------\n");
                printf("---N: %d\n", i + 1);
                printf("---Le ID de l'Avion: %d\n", avions[i].idAvion);
                printf("---Le modele de l'Avion: %s\n", avions[i].modele);
                printf("---La capacite de l'Avion: %d\n", avions[i].capacite);
                printf("---Le status de l'Avion: %s\n", avions[i].status);
                printf("---La date d'entree de l'Avion: %s\n", avions[i].dateEntree);
                printf("-----------------------------\n");
            }
            i++;
        }

        break;
    
    default:
        break;
    }


}


