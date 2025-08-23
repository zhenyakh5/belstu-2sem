#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

void extractColumn(const char* inputFileName, const char* outputFileName, int k) {
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    else printf("Файл открыт.\n");

    int numCols;
    if (fscanf(inputFile, "%d", &numCols) != 1) {
        printf("Ошибка чтения размерности матрицы\n");
        fclose(inputFile);
        return;
    }
    else printf("Чтение размерности прошло замечательно\n");

    double** matrix = (double**)malloc(numCols * sizeof(double*));
    for (int i = 0; i < numCols; ++i) {
        matrix[i] = (double*)malloc(numCols * sizeof(double));
    }

    for (int i = 0; i < numCols; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (fscanf(inputFile, "%lf", &matrix[i][j]) != 1) {
                printf("Ошибка чтения элемента матрицы\n");
                fclose(inputFile);

                for (int i = 0; i < numCols; ++i) {
                    free(matrix[i]);
                }
                free(matrix);

                return;
            }
        }
    }

    printf("Введите значение k (от 0 до %d): ", numCols - 1);
    if (scanf("%d", &k) != 1 || k < 0 || k >= numCols) {
        printf("Некорректный ввод для k\n");

        for (int i = 0; i < numCols; ++i) {
            free(matrix[i]);
        }
        free(matrix);

        fclose(inputFile);
        return;
    }

    double* column = (double*)malloc(numCols * sizeof(double));
    for (int i = 0; i < numCols; ++i) {
        column[i] = matrix[i][k];
    }

    fclose(inputFile);

    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Ошибка создания файла\n");

        for (int i = 0; i < numCols; ++i) {
            free(matrix[i]);
        }
        free(matrix);
        free(column);

        return;
    }
    else printf("Файл создан\n");

    for (int i = 0; i < numCols; ++i) {
        fprintf(outputFile, "%.1lf\n", column[i]);
    }

    fclose(outputFile);
    for (int i = 0; i < numCols; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(column);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int k;
    extractColumn("D:/University/oaip/2sem/lab2/input.txt", "D:/University/oaip/2sem/lab2/output.txt", 2);
    return 0;
}