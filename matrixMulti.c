#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3


static PyObject* py_echo( PyObject* self, PyObject* args ) {

    int i, j, k;
    int **A = (int**)malloc(N * sizeof(int*));
    int **B = (int**)malloc(N * sizeof(int*));
    int **C = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++)
    {
        A[i] = (int*)malloc(N * sizeof(int));
        B[i] = (int*)malloc(N * sizeof(int));
        C[i] = (int*)malloc(N * sizeof(int));
    }



    srand(time(NULL));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }



    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < N; k++)
            C[i][j] += A[i][k] * B[k][j];
        }




    printf("matrix A\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\nmatrix B\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("\nthe result of multiplying\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%3d ", C[i][j]);
        printf("\n");
    }







    for (i = 0; i < N; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);


    return Py_None;
}

static PyMethodDef matrixMulti_methods[] = {
   { "matrixMultiplication", py_echo, METH_NOARGS, "echo function" },
   { NULL, NULL }
};

static struct PyModuleDef matrixMultimodule = {
   PyModuleDef_HEAD_INIT,
   "matrixMulti",   /* name of module */
   NULL, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   matrixMulti_methods
};

//PyMODINIT_FUNC initownmod() {
PyMODINIT_FUNC PyInit_matrixMulti() {

   //(void)Py_InitModule( "matrixMulti", matrixMulti_methods );
   PyObject *m;

    m = PyModule_Create(&matrixMultimodule);
    if (m == NULL)
        return NULL;

   return m;
}
