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
    int userChoise = 0, i = 0, id = 0;
    char modele[100];

    printf("Que voulez vous utiliser come un utile de recherche (1.id, 2.modele): ");
    userChoise = acceptUserInput();

    if(userChoise == 1){
        id = acceptUserInput();
    } else if(userChoise == 2){
        printf("Donnez le model de l'avion: ");
        scanf("%[^\n]", modele);
    } else{
        printf("Choix Invalid!!!\n");
        return;
    }


    while ((i < MAX_PLANE_NUMBER && avions[i].idAvion != 0)) {
            if(userChoise == 1 ? (avions[i].idAvion == id) : (strcasecmp(avions[i].modele, modele) == 0)){
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
        printf("\n");
}

void sortplane(){
    int i = 0, userChoice = 0; 

    printf("Voulez vous triez les avions pas 1.Capacite ou 2.Model: ");
    userChoice = acceptUserInput();

    while(i < MAX_PLANE_NUMBER && avions[i].modele[0] != '\0'){
            i++;
        }

        if(userChoice < 1 || userChoice > 2){
            printf("Choix invalid!!");
            return;
        }

        for(int j = 0; j < i - 1; j++){
            for(int z = 0; z < i - j - 1; z++){
                if(userChoice == 1 ? (avions[z].capacite > avions[z + 1].capacite) : (strcasecmp(avions[z].modele, avions[z + 1].modele) > 0)){
                    struct Avion tmp = avions[z];
                    avions[z] = avions[z + 1];
                    avions[z + 1] = tmp;
                }
            }
        }

        
   
    listPlane();
    printf("Choix invalide!!\n");

}
