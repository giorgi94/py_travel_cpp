#include <iostream>
#include <vector>
#include <python3.6m/Python.h>
#include "binomial.h"
#include "travel.h"

static PyObject *Binomial(PyObject *self, PyObject *args)
{
    double n;
    int k;

    if (!PyArg_ParseTuple(args, "di", &n, &k))
    {
        return NULL;
    }

    return Py_BuildValue("d", binomial(n, k));
}

static PyObject *Travel(PyObject *self, PyObject *args)
{
    char *dirname;

    if (!PyArg_ParseTuple(args, "s", &dirname))
    {
        return NULL;
    }

    auto items = travel((std::string)dirname);
    int size = items.size();

    PyObject *seq = PyList_New(size);

    for (int i = 0; i < size; i++)
    {
        auto item = items[i];

        PyList_SetItem(seq, i,
                       Py_BuildValue(
                           "{s:s,s:s}",
                           "type",
                           item.first == 'd' ? "directory" : "file",
                           "path",
                           item.second.c_str()));
    }

    return seq;
}

static PyObject *version(PyObject *self)
{
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
    {"binomial", Binomial, METH_VARARGS, "calculates binomial number"},
    {"travel", Travel, METH_VARARGS, "travels through directories"},
    {"version", (PyCFunction)version, METH_NOARGS, "returns the version."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule",
    "My Module",
    -1,
    myMethods};

PyMODINIT_FUNC PyInit_myModule(void)
{
    return PyModule_Create(&myModule);
}