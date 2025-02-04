#include <stdio.h>
#include <string.h>
#define MAX_CARTAS 32 // 8 ESTADOS * 4 CIDADES CADA

// ESTRUTURA PARA ARMAZENAR DADOS DA CARTA
typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;

} Carta;

//FUNÇÃO PARA CADSATRAR UMA NOVA CARTA
void cadastrarcarta(Carta cartas[], int *totalCartas) {
    if (*totalCartas >= MAX_CARTAS){
        printf("\n Limite de cartas atingidos");
        return;
    }

    Carta novaCarta; 
//FUNÇÃO PARA CADASTRAR NOVA CARTA
    printf("\n--- Cadastro de Cartas ---\n");

//ESTADO
    printf(" Informe a letra do estado (A - H): ");
    scanf("%c", &novaCarta.estado);
    if (novaCarta.estado < 'A' || novaCarta.estado > 'H') {
        printf("Estado invalido! Deve estar entre A e H.\n");
        return;
    }
    

// CÓD DA CARTA
    printf("Informe o código da carta (EX: A01, H04): ");
    scanf("%3s", novaCarta.codigo);
    if (novaCarta.codigo[0] != novaCarta.estado || novaCarta.codigo[1] < '0' || novaCarta.codigo[1] > '9' || novaCarta.codigo[2] < '1' || novaCarta.codigo[2] > '4'){
        printf("Código invalido! Deve ser no formato correto (Ex: A01, H04).\n");
        return;
    }
    

//NOME DA CIDADE
    printf("Informe o nome da cidade: ");
    scanf("%[^\n]", novaCarta.cidade);

//POPULAÇÃO
    printf("Informe a População: ");
    scanf("%d", &novaCarta.populacao);

//AREA
    printf("Informe a área da cidade por Km²: ");
    scanf("%f", &novaCarta.area);

//PIB
    printf("Informe o PIB da cidade: ");
    scanf("%f", &novaCarta.pib);

//Pontos TURISTICOS
    printf("Informe o número de pontos turisticos: ");
    scanf("%d", &novaCarta.pontosturisticos);

    printf("\n Carta cadastrada com sucesso! \n");
}

//FUNÇÃO PARA EXIBIR TODAS AS CARTA CADASTRADA
void listarCartas(Carta cartas[], int totalCartas) {
    if (totalCartas == 0) {
        printf("\nNenhuma carta cadastrada ainda.\n");
        return;
    }
    
   printf("\n--- CARTA CADASTRADA ---\n");
   for (int i = 0; i < totalCartas; i++){
    printf("\nCarta %d\n", i + 1);
    printf("Código: %s\n", cartas[i].codigo);
    printf("Estado: %c\n", cartas[i].estado);
    printf("Cidade: %s\n", cartas[i].cidade);
    printf("População: %d\n", cartas[i].populacao);
    printf("Área: %.2f\n", cartas[i].area);
    printf("PIB: %.2F\n", cartas[i].pib);
    printf("Pontos Turisticos: %d\n", cartas[i].pontosturisticos);
   }
   
}

   




   
