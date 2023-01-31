#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

typedef struct {
    int id;
    char nome[20];
    char profissao[50];
    int idade;
} Pessoa;

// Função de ordenação InsertionSort pelo id
void insertionSort(Pessoa pessoas[], int cont);

// Função de ordenação SelectionSort pelo id
void selectionSort(Pessoa pessoas[], int cont);

// Função de ordenação ShellSort pelo id
void shellSort(Pessoa pessoas[], int cont);


#endif // METODOS_H_INCLUDED
