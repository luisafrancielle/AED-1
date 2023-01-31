#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "metodos.h"

// Função de ordenação InsertionSort pelo id
void insertionSort(Pessoa pessoas[], int cont) {
int i, j;

// Função de ordenação SelectionSort pelo id
void selectionSort(Pessoa pessoas[], int cont) {
    int i, j, min_idx;
    Pessoa temp;
    for (i = 0; i < cont-1; i++) {
        min_idx = i;
        for (j = i+1; j < cont; j++)
            if (pessoas[j].id < pessoas[min_idx].id)
                min_idx = j;
        temp = pessoas[min_idx];
        pessoas[min_idx] = pessoas[i];
        pessoas[i] = temp;
    }
}

// Função de ordenação ShellSort pelo id
void shellSort(Pessoa pessoas[], int cont) {
    int i, j, gap;
    Pessoa temp;
    for (gap = cont/2; gap > 0; gap /= 2) {
        for (i = gap; i < cont; i++) {
            temp = pessoas[i];
            for (j = i; j >= gap && pessoas[j - gap].id > temp.id; j -= gap) {
                pessoas[j] = pessoas[j - gap];
            }
            pessoas[j] = temp;
        }
    }
}


