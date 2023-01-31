#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, end;
double time_spent;

typedef struct {
    int id;
    char nome[20];
    char profissao[50];
    int idade;
} Pessoa;

// Função de ordenação InsertionSort pelo id
void insertionSort(Pessoa pessoas[], int cont) {
int i, j;

Pessoa chave;
for (i = 1; i < cont; i++) {
chave = pessoas[i];
j = i - 1;
   while (j >= 0 && pessoas[j].id > chave.id) {
        pessoas[j + 1] = pessoas[j];
        j = j - 1;
    }
    pessoas[j + 1] = chave;
    }
}

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

int main() {
    FILE *arquivo;
    char linha[100], nome[20], profissao[50];
    char nomeArquivo[30];
    int cont = 0;
    int cont2 = 0;
    int id = 0;
    int idade = 0;

    printf("Digite o nome do arquivo (incluindo a extensão): ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL){
        printf("Arquivo não existe ou foi digitado incorretamente!");
        return 1;
    }

    fgets(linha, 100, arquivo);  
    while(fgets(linha, 100, arquivo) != NULL){
        cont2++;
    }
    fclose(arquivo);

    Pessoa pessoas[cont2];

    arquivo = fopen(nomeArquivo, "r");

    // Ler a primeira linha <titulo> do .csv, assim,
    // Na próxima iteração já será descartada
    fgets(linha, 100, arquivo);  
    //Ler linha por linha do arquivo
    while(fgets(linha, 100, arquivo) != NULL){
        // Lemos cada linha do arquivo e guardamos cada coluna <separada por ;> 
        // com base no seu tipo de dado em uma variável
        // Por exemplo, %20[^;] significa que será armazenado uma string de até
        // 20 caracteres até aparecer um ";"
        sscanf(linha, "%d;%20[^;];%50[^;];%d", &id, nome, profissao, &idade);
        // sscanf(linha, "%d,%20[^,],%50[^,],%d", &id, nome, profissao, &idade);

        // Guardamos as variáveis da linha na struct
        pessoas[cont].id = id;
        strcpy(pessoas[cont].nome, nome);
        strcpy(pessoas[cont].profissao, profissao);
        pessoas[cont].idade = idade;

        cont++;
    }
    fclose(arquivo);

    // Ordena a lista de pessoas pelo id

    // Escolhe o metodo de ordenação
    int num;
    do{
        printf("Digite:\n (1) Para InsertShort\n (2) Para SelectSort\n (3) Para ShellShort\n\n");
        printf("Qual metodo voce deseja usar para fazer a ordenacao? \n");
        scanf("%i", &num);
        printf("\n");
    } while (num != 1 &&  num != 2 && num != 3);

        switch(num){
        case 1:
            start = clock();
            insertionSort(pessoas, cont);
            break;
        case 2:
            start = clock();
            selectionSort(pessoas, cont);
            break;
        case 3:
            start = clock();
            shellSort(pessoas, cont);
            break;
        default:
            printf("Opção invalida\n");
            break;
        }

    // Mostra a lista de pessoas ordenadas
    int i;
    for (i = 0; i < cont2; i++){
        printf("%d ", pessoas[i].id);
        printf("%s ", pessoas[i].nome);
        printf("%s ", pessoas[i].profissao);
        printf("%d\n", pessoas[i].idade);
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %f\n", time_spent);

    return 0;
}