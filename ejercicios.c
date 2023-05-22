#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101; // Genera números aleatorios entre 0 y 100
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int** matrix, int** transposedMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Ingrese el número de filas: ");
    scanf("%d", &rows);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    int** matrix = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Allocate memory for the transposed matrix
    int** transposedMatrix = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++) {
        transposedMatrix[i] = (int*)malloc(rows * sizeof(int));
    }

    fillMatrix(matrix, rows, cols);

    printf("\nMatriz Original:\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transposedMatrix, rows, cols);

    printf("\nMatriz Transpuesta:\n");
    printMatrix(transposedMatrix, cols, rows);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);

    return 0;
}
