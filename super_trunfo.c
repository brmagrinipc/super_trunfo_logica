
#include <stdio.h>

int main() {
    unsigned long int populacao1, populacao2;
    int pontos_tur1, pontos_tur2;
    float area1, pib1, densidade1, pib_per_capita1, super_poder1;
    float area2, pib2, densidade2, pib_per_capita2, super_poder2;
    char estado1[2], codigo1[4], cidade1[50];
    char estado2[2], codigo2[4], cidade2[50];

    int opcao1, opcao2;
    float valor1_c1 = 0, valor2_c1 = 0, valor1_c2 = 0, valor2_c2 = 0;

    // Entrada da primeira carta
    printf("Digite os dados da primeira carta \n");
    printf("Digite a letra do estado: \n");
    scanf("%s", estado1);
    printf("Digite o código da carta: \n");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", cidade1);
    printf("Digite a população: \n");
    scanf("%lu", &populacao1);
    printf("Digite a área da cidade: \n");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade: \n");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da cidade: \n");
    scanf("%d", &pontos_tur1);

    // Cálculos da primeira carta
    densidade1 = populacao1 / area1;
    pib_per_capita1 = pib1 / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + pontos_tur1 + pib_per_capita1 + (1.0 / densidade1);

    // Entrada da segunda carta
    printf("\nDigite os dados da segunda carta\n");
    printf("Digite a letra do estado: \n");
    scanf("%s", estado2);
    printf("Digite o código da carta: \n");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", cidade2);
    printf("Digite a população: \n");
    scanf("%lu", &populacao2);
    printf("Digite a área da cidade: \n");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade: \n");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da cidade: \n");
    scanf("%d", &pontos_tur2);

    // Cálculos da segunda carta
    densidade2 = populacao2 / area2;
    pib_per_capita2 = pib2 / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos_tur2 + pib_per_capita2 + (1.0 / densidade2);

    // Menu para escolha de atributos
    printf("\nEscolha dois atributos para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");

    printf("Escolha o primeiro atributo: ");
    scanf("%d", &opcao1);

    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) {
            printf("Você já escolheu esse atributo!\n");
        }
    } while (opcao2 == opcao1);

    // Seleção dos valores da carta 1
    switch(opcao1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos_tur1; valor1_c2 = pontos_tur2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pib_per_capita1; valor1_c2 = pib_per_capita2; break;
        default: printf("Opção inválida\n"); return 1;
    }

    switch(opcao2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos_tur1; valor2_c2 = pontos_tur2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pib_per_capita1; valor2_c2 = pib_per_capita2; break;
        default: printf("Opção inválida\n"); return 1;
    }

    // Resultado da comparação
    printf("\nResultado da Comparação:\n");
    printf("Cidade 1: %s\n", cidade1);
    printf("Cidade 2: %s\n", cidade2);

    printf("Atributo 1: %.2f x %.2f\n", valor1_c1, valor1_c2);
    printf("Vencedora: %s\n", (opcao1 == 5) ? (valor1_c1 < valor1_c2 ? cidade1 : cidade2) : (valor1_c1 > valor1_c2 ? cidade1 : cidade2));

    printf("Atributo 2: %.2f x %.2f\n", valor2_c1, valor2_c2);
    printf("Vencedora: %s\n", (opcao2 == 5) ? (valor2_c1 < valor2_c2 ? cidade1 : cidade2) : (valor2_c1 > valor2_c2 ? cidade1 : cidade2));

    float soma1 = (opcao1 == 5 ? -valor1_c1 : valor1_c1) + (opcao2 == 5 ? -valor2_c1 : valor2_c1);
    float soma2 = (opcao1 == 5 ? -valor1_c2 : valor1_c2) + (opcao2 == 5 ? -valor2_c2 : valor2_c2);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    if (soma1 > soma2)
        printf("Resultado Final: %s venceu a rodada!\n", cidade1);
    else if (soma2 > soma1)
        printf("Resultado Final: %s venceu a rodada!\n", cidade2);
    else
        printf("Resultado Final: Empate!\n");

    return 0;
}
