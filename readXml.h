//
// Created by louis-keolio on 27/11/2020.
//

#ifndef PROJET_GIT_ESGI_READXML_H
#define PROJET_GIT_ESGI_READXML_H

#endif //PROJET_GIT_ESGI_READXML_H

void fermetureFichier(FILE*);
void baliseOuvrante(FILE * ,struct Tag*); // lecture de la balise ouvrante
void lecturecontent(FILE *, struct Tag*); // lecture du content entre 2 balises
