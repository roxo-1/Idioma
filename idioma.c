// Carolina Lee - 10440304
// Pedro Henrique Saraiva Arruda - 10437747
#include <stdio.h>

int main() {
    char texto[100];  // Vetor para armazenar até 99 caracteres + '\0'
    int score_pt = 0;   // contador de frequência da letra A
    int score_en = 0;   // contador de frequência da letra E

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);  // Lê uma linha de texto com espaços

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        c = tolower(c);
        // Letras típicas do português
        if (c == 'ã' || c == 'õ' || c == 'á' || c == 'é' || c == 'í' || c == 'ó' || c == 'ú' || c == 'ç'){
            score_pt++;
        }
        //letras típicas do inglês
         if (c == 'h' || c == 'w' || c == 'y' || c == 'k' || c == 'x'){
            score_en++;
        }
    }
    if (score_pt > score_en) {
        printf("O idioma do texto é português.");
    } else if (score_en > score_pt) {
        printf("O idioma do texto é inglês.");
    } else {
        printf("Não foi possível detectar o idioma com base nas letras analisadas.");
    }

    return 0;
}