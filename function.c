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
        
        printf("-->Quelle est le status de l'avion: (0.Disponible 1.Maintenance 2.En vol)");
        userStatusChoice = acceptUserInput();
        
        printf("-->donnez la date d''entree de l'avion: ");
        scanf("%[^\n]", planeEntranceDate);
        
        printf("%s\n", planeModele);
        printf("%s\n", planeEntranceDate);

        printf("\n");

        // ading plane id to the airport flotte and  incrementing the number of planess
        for(int i = 0; i < MAX_PLANE_NUMBER; i++){
            if(aeroport.flotte[i] == 0){
                aeroport.flotte[i] = planeID;
                break;
            }
        }
        aeroport.nbAvion += 1;

        avions[numberOfPlanesAvilable].idAvion = planeID++;
        strcpy(avions[numberOfPlanesAvilable].modele, planeModele);
        strcpy(avions[numberOfPlanesAvilable].status, userStatusChoice > 2 || userStatusChoice < 0 ? status[1] : status[userStatusChoice]);
        avions[numberOfPlanesAvilable].capacite = planeCapacity;
        strcpy(avions[numberOfPlanesAvilable].dateEntree, planeEntranceDate);
        
        if(userStatusChoice > 2 || userStatusChoice < 0 ){
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
            printf("VOUS AVEZ ENTRE UN CHOIX INVALIDE POUR LE STATUT, IL A DONC ÉTÉ PARAMÉTRÉ SUR \"EN MAINTENANCE\". VOUS POUVEZ LE MODIFIER PLUS TARD.\n");
            printf("!!!!!!!!!!WARNING!!!!!!!!!\n");
        }



        userChoice--;
        numberOfPlanesAvilable++;
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

    while(i <  numberOfPlanesAvilable ){        
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

    for(int j = i; j < numberOfPlanesAvilable; j++){
        avions[j] = avions[j + 1];
    }



    // removing the plaine if from the airport and decrementing the the number of plains available
    for(int p = 0; p < MAX_PLANE_NUMBER; p++){
        if(aeroport.flotte[p] == target){
            aeroport.flotte[p] = 0;
            break;
        }
    }
    aeroport.nbAvion -= 1;

    strcpy(avions[numberOfPlanesAvilable].modele , "");
    strcpy(avions[numberOfPlanesAvilable].dateEntree, "");
    strcpy(avions[numberOfPlanesAvilable].status, "");

    printf("L'avion a été supprimé avec succès!!");
    numberOfPlanesAvilable--;
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


    while (i < numberOfPlanesAvilable) {
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

void listAirportInfo(){

    int i = 0;

    printf("\n");
    printf("--------------------------------------------\n");
    printf("le nom de l'aeroport est: %s\n", aeroport.name);
    printf("le nomre d'avions a l'aeroport est: %d\n", aeroport.nbAvion);
    for(i = 0; i < MAX_PLANE_NUMBER; i++){
        if(i == 0){
            printf("Les avions present au aeroport sont: \n");
        }

        if(aeroport.flotte[i] == 0) continue;

        for(int j = 0; j < MAX_PLANE_NUMBER ; j++){
            if(avions[j].idAvion == aeroport.flotte[i]){
                printf("-----------------------------\n");
                printf("---N: %d\n", i + 1);
                printf("---Le ID de l'Avion: %d\n", avions[j].idAvion);
                printf("---Le modele de l'Avion: %s\n", avions[j].modele);
                printf("---La capacite de l'Avion: %d\n", avions[j].capacite);
                printf("---Le status de l'Avion: %s\n", avions[j].status);
                printf("---La date d'entree de l'Avion: %s\n", avions[j].dateEntree);
                printf("-----------------------------\n");
                printf("\n");
            }
        }
    }
    printf("-------------end of info---------\n");


}

void calculateCoef(){
    int coeff = 0, dispo = 0;
    float result = 0.0;

    for(int i = 0; i < MAX_PLANE_NUMBER; i++){
        if(strcasecmp(avions[i].status, "Disponible") == 0) dispo++;
    }

    result = ((float)dispo / numberOfPlanesAvilable) * 100;

    printf("Le nomre d'aviaon disponible est: %d\n", dispo);
    printf("Le coefficient d'occupation du parc est de %.2f%%.\n", result);

}

