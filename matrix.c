#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix dynamically
int** createMatrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    return matrix;
}

// Function to input values into a matrix
void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int **A, int **B, int r1, int c1, int c2) {
    int **C = createMatrix(r1, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Check multiplication condition
    if (c1 != r2) {
        printf("Matrix multiplication not possible! (c1 != r2)\n");
        return 0;
    }

    // Create matrices dynamically
    int **A = createMatrix(r1, c1);
    int **B = createMatrix(r2, c2);

    // Input matrices
    printf("\nInput for Matrix A:\n");
    inputMatrix(A, r1, c1);
    printf("\nInput for Matrix B:\n");
    inputMatrix(B, r2, c2);

    // Multiply matrices
    int **C = multiplyMatrices(A, B, r1, c1, c2);

    // Display result
    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);
    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);
    printf("\nResultant Matrix C (A x B):\n");
    displayMatrix(C, r1, c2);

    // Free allocated memory
    for (int i = 0; i < r1; i++) free(A[i]);
    free(A);
    for (int i = 0; i < r2; i++) free(B[i]);
    free(B);
    for (int i = 0; i < r1; i++) free(C[i]);
    free(C);

    return 0;
}
