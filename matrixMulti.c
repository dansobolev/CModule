#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3


static PyObject* MatrixMultiplication( PyObject* self, PyObject* args ) {

    PyObject* list1;
    PyObject* list2;
    int i, j, k;
    int len1; len2;

    if (!PyArg_ParseTuple(args, "Ob", &list1, &list2)){
        return NULL;
    }
    len1 = PySequence_Fast_GET_SIZE(list1);
    len2 = PySequence_Fast_GET_SIZE(PySequence_Fast_GET_ITEM(list,2));

    for (c=0; c<len1; c++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, c);
        for (i=0; i<len2; i++){
            PyObject* item2 = PySequence_Fast_GET_ITEM(item1, i);
            for (j=0; j<len2; j++){
                PyObject* item3 = PySequence_Fast_GET_ITEM(item1, j);
                C[i][j] = 0;
                for (k=0; k<len2; k++){
                    C[i][j] += item2*item3
                }
            }
        }
    }

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < N; j++)
            printf("%3d ", C[i][j]);
        printf("\n");
    }
    `


    return Py_None;
}

static PyMethodDef matrixMulti_methods[] = {
    wd{
        "matrixMultiplication",
        MatrixMultiplication,
        METH_NOARGS,
        "multiplication between two matrices"
    },
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
