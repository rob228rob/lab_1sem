#include <stdio.h>
#include <malloc.h>

int main()
{

    FILE *file = fopen("a.txt", "r");
    int size1;
    fscanf(file, "%d", &size1);

    int rows = size1;
    int cols = size1;
    int matrix[rows][cols];
    int min_sm = 100*100;
    int max_sm = 0;
    int min_row0, max_row0;
    int *min_row = malloc(size1 * sizeof(int));
    int *max_row = malloc(size1 * sizeof(int));

    for (int i = 0; i < rows && !feof(file) && !ferror(file); i++)
    {
        int curr_sm = 0;
        for (int j = 0; j < cols && !feof(file) && !ferror(file); j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
            curr_sm += matrix[i][j];
            if (j == cols - 1 && curr_sm > max_sm){
                max_sm = curr_sm;
                max_row0 = i;

            }
            if (j == cols - 1 && curr_sm < min_sm) {
                min_sm = curr_sm;
                min_row0 = i;
            }
        }
        printf("\n");
    }

    fclose(file);

    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == max_row0) {
            max_row[j] = matrix[i][j];
            }
            if (i == min_row0) {
            min_row[j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == max_row0) {
                matrix[i][j] = min_row[j];
            }
            if (i == min_row0) {
                matrix[i][j] = max_row[j];
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}




