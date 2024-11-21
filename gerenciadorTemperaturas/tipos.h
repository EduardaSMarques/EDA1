#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    char cidade[20];      // Nome da cidade
    float *temperatura;   // Ponteiro para a temperatura registrada
} TMedidas;

typedef struct {
    int qtde_dias;        // Quantidade máxima de dias (limite de registros)
    int qtde_medidas;     // Quantidade atual de registros
    TMedidas *medidas;    // Vetor dinâmico para armazenar as medidas
} TTemperaturas;

#endif