#include  "header.h";

void AddPlane(){

    int userChoice = 0;
    char planeModele[100], planeStatus[100], planeEntranceDate[5];
    char status[][20] = {"Disponible", "En maintenance", "En vole"};
    int userStatusChoice = -1, planeCapacity = 9;
    int i = 0;

    printf("Combier d'avion vous voulez ajoutez: ");
    userChoice = acceptUserInput();

    while(userChoice >0){
        userStatusChoice = -1;

        printf("-->Donnez le modele de l'avion: ");
        fgets(planeModele, sizeof(planeModele), stdin);
        planeModele[strspn(planeModele, "\n")] = '\0';
        
        printf("-->Quelle est la capacite de l'avion: ");
        planeCapacity = acceptUserInput();

        printf("-->Quelle est le status de l'avion: ");
        userStatusChoice = acceptUserInput();



        printf("-->donnez la date d''entree de l'avion: ");
        fgets(planeEntranceDate, sizeof(planeEntranceDate), stdin);
        planeEntranceDate[strspn(planeEntranceDate, "\n")] = '\0';

        while(avions[i].model[0] != '\0'){
            i++;
        }

        avions[i].idAvion = planeID++;
        strcpy(avions[i].model, planeModele);
        strcpy(avions[i].status, userStatusChoice > 2 || userStatusChoice < 0 ? status[1] : status[userStatusChoice]);
        avions[i].capacite = planeCapacity;
        strcpy(avions[i].dateEntree, planeEntranceDate);
        
        if(userStatusChoice> 3 && userStatusChoice){
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
            printf("VOUS AVEZ ENTRE UN CHOIX INVALIDE POUR LE STATUT, IL A DONC ÉTÉ PARAMÉTRÉ SUR \"EN MAINTENANCE\". VOUS POUVEZ LE MODIFIER PLUS TARD.\n");
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
        }

    }

}

