#include <stdio.h>
#define MAX_CARTAS 32

int main() {
    //INFORMAÇÕES SOBRE AS CARTAS
    char estados[MAX_CARTAS];
    char codigos[MAX_CARTAS][4];
    char nomes[MAX_CARTAS][50];
    unsigned long int populacoes[MAX_CARTAS];
    float areas[MAX_CARTAS];
    float pibs[MAX_CARTAS];
    int pontosTuristicos[MAX_CARTAS];
    float densidade[MAX_CARTAS];
    float pibPerCapita[MAX_CARTAS];
    float superTrunfo[MAX_CARTAS];

    int totalCartas, i, carta1, carta2;
    
    //CADASTRO DAS CARTAS
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &totalCartas);

    if (totalCartas > MAX_CARTAS) {
        printf("Número máximo de cartas é %d.\n", MAX_CARTAS);
        return 1;
    }

    for (i = 0; i < totalCartas; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);
        
        printf("Estado (A-H): ");
        scanf(" %c", &estados[i]);
        while (getchar() != '\n');
        

        printf("Código (Ex: A01): ");
        scanf("%s", codigos[i]);
        while (getchar() != '\n');


        printf("Nome da cidade: ");
        scanf(" %[^\n]", nomes[i]);
        while (getchar() != '\n');



        printf("População: ");
        scanf("%lu", &populacoes[i]);

        printf("Área (km²): ");
        scanf("%f", &areas[i]);

        printf("PIB: ");
        scanf("%f", &pibs[i]);

        printf("Pontos turísticos: ");
        scanf("%d", &pontosTuristicos[i]);


        //CALCULAR DENSIDADE E PIB PER CAPITA
        densidade[i] = (areas[i] > 0) ? (populacoes[i] / areas[i]) : 0;
        pibPerCapita[i] = (populacoes[i] > 0) ? (pibs[i] / populacoes[i]) : 0;
        superTrunfo[i] = populacoes[i] + areas[i] + pibs[i] + pibPerCapita[i] + pontosTuristicos[i] + (1 / (densidade[i] + 1));
    }

    //EXIBE TODAS AS CARTAS CADASTRADAS
    printf("\n--- CARTAS CADASTRADAS ---\n");
    for (i = 0; i < totalCartas; i++) {
        printf("\nCarta %d\n", i + 1);
        printf("Estado: %c\n", estados[i]);
        printf("Código: %s\n", codigos[i]);
        printf("Nome da cidade: %s\n", nomes[i]);
        printf("População: %lu habitantes\n", populacoes[i]);
        printf("Area: %.2f Km²\n", areas[i]);
        printf("PIB: %.2f bilhoes\n", pibs[i]);
        printf("Pontos turisticos: %d\n", pontosTuristicos[i]);
        printf("Densidade Populacional: %.2f hab/Km²\n", densidade[i]);
        printf("PIB per Capita: %.2f\n", pibPerCapita[i]);
        printf("Super Trunfo: %.2f\n", superTrunfo[i]);

        
    }

    //ESCOLHER CARTAS PARA COMPARAR
    printf("\nEscolha duas cartas para comparar (digite os números de 1 a %d): ", totalCartas);
    scanf("%d %d", &carta1, &carta2);
    carta1--;
    carta2--;

    //MENU DINAMICO PARA ESCOLHER ATRIBUTOS
    int atributo1, atributo2;
    int opcoes[6] = {1, 2, 3, 4, 5, 6}; //ATRIBUTOS DISPONIVEIS

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d", &atributo1);


    //REMOVE A OPÇÃO JA ESCOLHIDA NO MENU
    printf("\nEscolha o segundo atributo para comparar:\n");
    for (i = 0; i < 6; i++) {
        if (opcoes[i] != atributo1) {
            printf("%d. ", opcoes[i]);
            switch (opcoes[i]) {
                case 1: printf("População\n"); break;
                case 2: printf("Área\n"); break;
                case 3: printf("PIB\n"); break;
                case 4: printf("Pontos Turísticos\n"); break;
                case 5: printf("Densidade Populacional\n"); break;
                case 6: printf("PIB per Capita\n"); break;
            }
        }
    }
    scanf("%d", &atributo2);


    //FUNÇÃO PARA COMPARAR ATRIBUTOS
    float valor1, valor2, soma1 = 0, soma2 = 0;

    //PRIMEIRA COMPARAÇÃO
    switch (atributo1) {
        case 1: valor1 = populacoes[carta1]; valor2 = populacoes[carta2]; break;
        case 2: valor1 = areas[carta1]; valor2 = areas[carta2]; break;
        case 3: valor1 = pibs[carta1]; valor2 = pibs[carta2]; break;
        case 4: valor1 = pontosTuristicos[carta1]; valor2 = pontosTuristicos[carta2]; break;
        case 5: valor1 = densidade[carta1]; valor2 = densidade[carta2]; break;
        case 6: valor1 = pibPerCapita[carta1]; valor2 = pibPerCapita[carta2]; break;
    }
    printf("\n%s (%s) - %s: %.2f\n", nomes[carta1], codigos[carta1], (atributo1 == 5) ? "Densidade Populacional" : "Atributo 1", valor1);
    printf("%s (%s) - %s: %.2f\n", nomes[carta2], codigos[carta2], (atributo1 == 5) ? "Densidade Populacional" : "Atributo 1", valor2);
    soma1 += (atributo1 == 5) ? (1 / valor1) : valor1;
    soma2 += (atributo1 == 5) ? (1 / valor2) : valor2;

    //SEGUNDA COMPARAÇÃO
    switch (atributo2) {
        case 1: valor1 = populacoes[carta1]; valor2 = populacoes[carta2]; break;
        case 2: valor1 = areas[carta1]; valor2 = areas[carta2]; break;
        case 3: valor1 = pibs[carta1]; valor2 = pibs[carta2]; break;
        case 4: valor1 = pontosTuristicos[carta1]; valor2 = pontosTuristicos[carta2]; break;
        case 5: valor1 = densidade[carta1]; valor2 = densidade[carta2]; break;
        case 6: valor1 = pibPerCapita[carta1]; valor2 = pibPerCapita[carta2]; break;
    }
    printf("%s (%s) - Atributo 2: %.2f\n", nomes[carta1], codigos[carta1], valor1);
    printf("%s (%s) - Atributo 2: %.2f\n", nomes[carta2], codigos[carta2], valor2);
    soma1 += (atributo2 == 5) ? (1 / valor1) : valor1;
    soma2 += (atributo2 == 5) ? (1 / valor2) : valor2;

    //RESULTADO FINAL
    printf("\nSOMA DOS ATRIBUTOS: %.2f vs %.2f\n", soma1, soma2);
    printf("Resultado: %s\n", (soma1 > soma2) ? "Carta 1 vence!" : (soma1 < soma2) ? "Carta 2 vence!" : "Empate!");

    return 0;
}