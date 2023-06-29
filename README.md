# projetoGrafo

Este programa em C lê uma matriz de adjacência de um arquivo de texto e imprime o grafo correspondente no formato solicitado.

## Requisitos

- Compilador de C (ex: GCC)

## Como Usar

1. Certifique-se de ter um arquivo de texto contendo a matriz de adjacência no seguinte formato:

      v1  v2  v3  v4  v5  v6
    v1  0   33  44  22  17  11
    v2  -   0   19  45  7   77
    v3  -   -   0   0   30  24
    v4  -   -   -   0   10  5
    v5  -   -   -   -   0   9
    v6  -   -   -   -   -   0

2. Abra o arquivo `main.c` e ajuste os valores das constantes conforme necessário:

    - `MAX_VERTICES`: Define o número máximo de vértices do grafo.
    - `MAX_NOME`: Define o tamanho máximo do nome de cada vértice.
    - `nomeArquivo`: Especifique o nome do arquivo de texto contendo a matriz de adjacência.

3. Compile o programa utilizando o compilador de C. Por exemplo, com o GCC:

    ```bash
    gcc main.c -o programa
    ```

4. Execute o programa:

    ```bash
    ./programa
    ```

5. O programa lerá a matriz de adjacência do arquivo especificado e imprimirá o grafo no seguinte formato:

    ```
    Grafo:
    v1: v2(33) v3(44) v4(22) v5(17) v6(11)
    v2: v3(19) v4(45) v5(7) v6(77)
    v3: v5(30) v6(24)
    v4: v5(10) v6(5)
    v5: v6(9)
    ```

## Observações

- Certifique-se de que o arquivo de texto esteja formatado corretamente, seguindo o exemplo fornecido.
- Ajuste o tamanho máximo de vértices (`MAX_VERTICES`) e o tamanho máximo do nome de cada vértice (`MAX_NOME`) de acordo com suas necessidades.
- O programa suporta até 10 vértices, mas você pode aumentar esse valor aumentando o tamanho da matriz `grafo` e do vetor `vertices` no código-fonte.
