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