#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

// Função para resetar as temperaturas
void reset(TTemperaturas *temp) {
    printf("Informe a quantidade de dias: ");
    scanf("%d", &(temp->qtde_dias));
    
    temp->medidas = (TMedidas *)malloc(temp->qtde_dias * sizeof(TMedidas));
    temp->qtde_medidas = 0;

    printf("Sistema resetado para %d dias.\n", temp->qtde_dias);
}

// Função para inserir uma medida
void inserir_medida(TTemperaturas *temp) {
    if (temp->qtde_medidas >= temp->qtde_dias) {
        printf("Limite de medidas atingido.\n");
        return;
    }

    TMedidas *medida = &temp->medidas[temp->qtde_medidas];
    printf("Informe o nome da cidade: ");
    scanf("%s", medida->cidade);
    
    medida->temperatura = (float *)malloc(sizeof(float));
    printf("Informe a temperatura: ");
    scanf("%f", medida->temperatura);

    temp->qtde_medidas++;
    printf("Medida registrada.\n");
}

// Função para exibir estatísticas
void estatistica(TTemperaturas *temp) {
    if (temp->qtde_medidas == 0) {
        printf("Nenhuma medida registrada.\n");
        return;
    }

    float soma = 0, maior = -1e9, menor = 1e9;
    char maior_cidade[20], menor_cidade[20];

    for (int i = 0; i < temp->qtde_medidas; i++) {
        float temp_atual = *(temp->medidas[i].temperatura);
        soma += temp_atual;

        if (temp_atual > maior) {
            maior = temp_atual;
            strcpy(maior_cidade, temp->medidas[i].cidade);
        }

        if (temp_atual < menor) {
            menor = temp_atual;
            strcpy(menor_cidade, temp->medidas[i].cidade);
        }
    }

    printf("Temperatura média: %.2f\n", soma / temp->qtde_medidas);
    printf("Maior temperatura: %.2f em %s\n", maior, maior_cidade);
    printf("Menor temperatura: %.2f em %s\n", menor, menor_cidade);
}

// Função para desalocar memória
void liberar_memoria(TTemperaturas *temp) {
    for (int i = 0; i < temp->qtde_medidas; i++) {
        free(temp->medidas[i].temperatura);
    }
    free(temp->medidas);
    printf("Memória desalocada. Saindo...\n");
}

// Função principal
int main() {
    TTemperaturas temp;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Reset\n");
        printf("2. Inserir Medida\n");
        printf("3. Estatística\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                reset(&temp);
                break;
            case 2:
                inserir_medida(&temp);
                break;
            case 3:
                estatistica(&temp);
                break;
            case 4:
                liberar_memoria(&temp);
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}