
#include <stdio.h>
#include <string.h>
#include "filebinomiale.h"

int Degre(Tournoi t) {
    int degre = 0;
    ArbreBinomialeNode* current = t.racine->child;

    while (current != NULL) {
        degre++;
        current = current->frere;
    }
    return degre;
}

bool EstVide(Tournoi t) {
    return t.racine == NULL;
}


