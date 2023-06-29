#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_NOME 10

void imprimirGrafo(int grafo[MAX_VERTICES][MAX_VERTICES], int numVertices, char vertices[MAX_VERTICES][MAX_NOME]) {
    printf("Grafo:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%s: ", vertices[i]);
        for (int j = 0; j < numVertices; j++) {
            if (grafo[i][j] != 0) {
                printf("%s(%d) ", vertices[j], grafo[i][j]);
            }
        }
        printf("\n");
    }
}

void lerMatrizAdjacencia(char* nomeArquivo, int grafo[MAX_VERTICES][MAX_VERTICES], int* numVertices, char vertices[MAX_VERTICES][MAX_NOME]) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo);  // Ignora a primeira linha do arquivo

    int i = 0, j = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char* token = strtok(linha, " ");
        int indice = 0;
        while (token != NULL) {
            if (indice == 0) {
                strcpy(vertices[i], token);
            } else {
                if (strcmp(token, "-") == 0) {
                    grafo[i][j] = 0;
                } else {
                    grafo[i][j] = atoi(token);
                }
                j++;
            }
            token = strtok(NULL, " ");
            indice++;
        }
        i++;
        j = 0;
    }

    *numVertices = i;

    fclose(arquivo);
}

int main() {
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int numVertices = 0;
    char vertices[MAX_VERTICES][MAX_NOME];
    char* nomeArquivo = "matriz_adjacente";

    lerMatrizAdjacencia(nomeArquivo, grafo, &numVertices, vertices);
    imprimirGrafo(grafo, numVertices, vertices);

    return 0;
}
