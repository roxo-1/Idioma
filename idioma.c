// Carolina Lee - 10440304
// Pedro Henrique Saraiva Arruda - 10437747

#include <stdio.h>
#include <ctype.h> //biblioteca para transformar todos os caracteres em letra minuscula
#include <locale.h> //biblioteca utilizada para ler os caracteres especiais
#include <string.h> //utilização de strings para verificar qual idioma mais utiliza a letra em questão

int main() {
    setlocale(LC_ALL, "");  // Configura a localidade do sistema, ou seja, inclui regras de formatação da localidade do sistema do usuário, no caso, do Brasil(para permitir o uso de "Ç" e outros caracteres com acento)

    char texto[100];  // Vetor para armazenar até 99 caracteres + '\0'
    int score_pt = 0;   // contador de frequência de letras mais comuns do português
    int score_en = 0;   // contador de frequência de letras mais comuns do inglês

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);  // Lê uma linha de texto com espaços

    for (int i = 0; texto[i] != '\0'; i++) { //Laço para ser capaz de passar a verificação por cada letra (e caso necessário, passar para minúscula), e então incrementar em 1 o devido contador
        char c = texto[i];
        c = tolower(c);  // Converte cada caractere para minúsculo

        // Letras do comuns do português usando strings para reconhecer os caracteres especiais
        if (strchr("ãõáéíóúâêîôûçacdfjmopqrsuvxz", c)) {
            score_pt++; //contador de caracteres mais comuns do português
        }

        // Letras mais comuns do inglês usando strings
        if (strchr("beghiklntwy", c)) {
            score_en++; //contador de caracteres mais comuns do inglês
        }
    }
    
    // Verifica fora do laço qual idioma tem maior pontuação
    if (score_pt > score_en) {
        printf("O idioma do texto esta em portugues.\n");
    } else if (score_en > score_pt) {
        printf("O idioma do texto esta em ingles.\n");
    } else {
        printf("Nao foi possivel detectar o idioma com base nas letras analisadas.\n");
    }

    return 0;
}