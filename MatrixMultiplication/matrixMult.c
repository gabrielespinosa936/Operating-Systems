//Gabriel Espinosa
//Lab/Task: Lab04
//February 18, 2019
#include "matrixMult.h"

int main(int argc, char *argv[]) {
    if (freopen(argv[1], "r", stdin) == 0) oops("Cannot open the input file.\n", -1);

    int **a1, **b1, **c1, **a2, **b2, **c2; // matrices
    int m1, k1, n1, m2, k2, n2; // dimensions of the matices m x k and k x n

    allocateAndLoadMatrices(&a1, &b1, &c1, &m1, &k1, &n1);
    allocateAndLoadMatrices(&a2, &b2, &c2, &m2, &k2, &n2);
    free_tids(multiply(a1, b1, c1, m1, k1, n1), m1);
    free_tids(multiply(a2, b2, c2, m2, k2, n2), m2);

    // the real magic happens in there

    // TODO: implement

    // dispaly results of matrix multiplication


    //printf(" I am here 1");


    printf("\nMATRIX A1\n");
    displayMatrix(a1, m1, k1);
    freeMatrix(a1, m1);
    printf("\nMATRIX B1\n");
    displayMatrix(b1, k1, n1);
    freeMatrix(b1, k1);
    printf("\nMATRIX A1 x B1\n");
    displayMatrix(c1, m1, n1);
    freeMatrix(c1, m1);

    //printf("I am here 2");

    printf("\nMATRIX A2\n");
    displayMatrix(a2, m2, k2);
    freeMatrix(a2, m2);
    printf("\nMATRIX B2\n");
    displayMatrix(b2, k2, n2);
    freeMatrix(b2, k2);
    printf("\nMATRIX A2 x B2\n");
    displayMatrix(c2, m2, n2);
    freeMatrix(c2, m2);

    return 0;
}

void *matrixThread(void *param) {
    // map the parameter onto the structure
    MATRIX_CELL *cell = (MATRIX_CELL *) param;
    for (int l = 0; l < cell->k; l++)
        (cell->c)[cell->i][cell->j] += (cell->a)[cell->i][l] * (cell->b)[l][cell->j];
    // TODO: implement


    free(cell);

    return NULL;
}

void allocateAndLoadMatrices(int ***a, int ***b, int ***c, int *m, int *k, int *n)
// takes pointers to two-dimensional matrices, so they can be allocated in here
// and used by the caller
{
    if (scanf("%d %d %d", m, k, n) == 0) oops("Cannot read matrix sizes.\n", -2);

    // TODO: implement
// 2 will point to the column
    (*a) = (int **) malloc((*m) * sizeof(int *));
    for (int i = 0; i < *m; i++) {
        (*a)[i] = (int *) malloc(*k * sizeof(int));
    }
    loadMatrix(a, *m, *k);
    (*b) = (int **) malloc((*k) * sizeof(int *));
    for (int i = 0; i < *k; i++) {
        (*b)[i] = (int *) malloc(*n * sizeof(int));
    }
    loadMatrix(b, *k, *n);
    (*c) = (int **) malloc((*n) * sizeof(int *));
    for (int i = 0; i < *m; i++) {
        (*c)[i] = (int *) calloc(*n, *n * sizeof(int));
    }


}

void loadMatrix(int ***matrix, int m, int n) {
    // TODO: implement
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &((*matrix)[i][j])); //get address of i and j

        }
    }

}

void freeMatrix(int **matrix, int m) {
    // TODO: implement
    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
}

pthread_t **multiply(int **a, int **b, int **c, int m, int k, int n) {
    pthread_t **tids = alloc_tids(m, n);

    // TODO: implement
    // Can use thread_join just not right after creating
/*
 * for i = 0 i < m i++
 * for j = 0 j < n j++
 * for q = 0 q < n q++------> Separate for threading
 *     C[i][j] += A[i][q]* B[q][j]-----> Separate for threading
 *
 */
    //MATRIX_CELL theCells;
    //theCells = calloc(m*n, sizeof(theCells));
    // Can use join only after we create AJ

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
//            //matrixCell
            MATRIX_CELL *cell = malloc(sizeof(MATRIX_CELL));
            cell->i = i;
            cell->j = j;
            cell->k = k;
            cell->a = a;
            cell->b = b;
            cell->c = c;
            pthread_create(&tids[i][j], NULL, matrixThread, (void *) cell);
        }
    }//for(int l = 0; l < m*n; l++)
//    {
//       join(&tids[l],m,n);    ---> in matrixThread
//    }
    join(tids, m, n);
    return tids;
}

pthread_t **alloc_tids(int m, int n) {
    pthread_t **tids;

    // TODO: implement
    *(&(tids)) = (pthread_t *) malloc(m * (sizeof(pthread_t)));

    for (int i = 0; i < m; i++) {
        tids[i] = (pthread_t *) malloc(n * (sizeof(pthread_t)));
    }

    return tids;
}

void free_tids(pthread_t **tids, int m) {
    // TODO: implement
    for (int i = 0; i < m; i++) {
        free(tids[i]);
    }
    free(tids);
}

void join(pthread_t **tids, int m, int n) {
    // TODO: implement
    // can use thread_join just have to use it later
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pthread_join(tids[i][j], NULL);
        }
    }

}

void displayMatrix(int **matrix, int m, int n) {
    // TODO: implement
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");

    }
}

