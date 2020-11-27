//
// Created by louis-keolio on 27/11/2020.
//
#include "readXml.h"

void fermetureFichier(FILE* f){
    fclose(f);
    printf(" \n Fermeture du fichier!\n");
}

void baliseOuvrante(FILE *f, struct Tag *tab){ // detection de la balise ouvrante et stockage du nom de la balise
    char a = (char)fgetc(f);
    char nomBalise[50]; // variable temporaire de stockage d'information
    int compteur = 0;
    int posedeAtt=0; // 0 si faux, 1 si vrai
    while ( a != '<'){ // recherche balise d'ouverture
        a = (char)fgetc(f);
    }
    char c = (char)fgetc(f);
    while ( c != '>'){
        nomBalise[compteur]=c;
        compteur++;
        c = (char)fgetc(f);

        if(c==' ' && posedeAtt == 0)
        {
            posedeAtt=1;
            nomBalise[compteur]='\0';
        }
        if(posedeAtt==1)
        {
            tab->start = malloc(sizeof(char )* strlen(nomBalise));
            strcpy(tab->start ,nomBalise);
            compteur = 0;
            posedeAtt = 2;
        }
    }
    nomBalise[compteur] = '\0';
    if( posedeAtt==0){
        tab->start = malloc(sizeof(char )* strlen(nomBalise));
        strcpy(tab->start ,nomBalise);
    }else{
        char * tempo = nomBalise;
        decoupeAttribut(f,tempo, tab, compteur);
    }
}