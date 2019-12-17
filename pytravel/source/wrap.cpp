#include <iostream>
#include <Python.h>
#include <exception>

#include "travel.h"

static PyObject *wrap_travel(PyObject *self, PyObject *args)
{
    char *dirname;

    if (!PyArg_ParseTuple(args, "s", &dirname))
    {
        return NULL;
    }

    PyObject *seq = PyList_New(0);

    std::list<filetype> items;

    try
    {
        items = travel((std::string)dirname);
    }
    catch (const std::runtime_error &re)
    {
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
    }

    for (auto it = items.begin(); it != items.end(); it++)
    {
        PyList_Append(seq,
                      Py_BuildValue(
                          "{s:i,s:s,s:s,s:i,s:i,s:i}",
                          "isdir", (*it).isdir ? 1 : 0,
                          "filename", (*it).filename.c_str(),
                          "fullpath", (*it).fullpath.c_str(),
                          "ctime", (*it).ctime,
                          "mtime", (*it).mtime,
                          "size", (*it).size));
    }

    return seq;
}

static PyObject *version(PyObject *self)
{
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
    {"_travel", wrap_travel, METH_VARARGS, "travels through directories"},
    {"version", (PyCFunction)version, METH_NOARGS, "returns the version."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "lib",
    "travels through directories",
    -1,
    myMethods};

PyMODINIT_FUNC PyInit_lib(void)
{
    return PyModule_Create(&myModule);
}
