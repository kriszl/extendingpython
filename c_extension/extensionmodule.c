#include <Python.h>
#include <stdbool.h> // flag is responsible need to use printf in order to print out the result of the is_prime

static PyObject *is_prime(PyObject *self, PyObject *args)
{
    /*
    A function that checks whether the given number, which has type int, is a prime or not.
    Return true or false to the Python interpreter depending on the result.
    */
    int number;
    bool flag;

    if (!PyArg_ParseTuple(args, "i", &number))
        return NULL;

    for (int divisor = 2; divisor * divisor <= number; divisor++)
        if (number % divisor == 0)
            flag = false;
        else
            flag = true;

    printf("%s\n", flag ? "true" : "false");

    Py_RETURN_NONE;
}

static PyObject *prime_factors(PyObject *self, PyObject *args)
{
    /*
    Print out all prime factors to the Python Interpreter | in future make this as an array of pointers (?)
    Returns nothing.
    */
    int number;

    if (!PyArg_ParseTuple(args, "i", &number))
        return NULL;
    
    while (number % 2 == 0) {
        printf("%d ", 2);
        number /= 2;
    }
    
    for (int divisor = 3; divisor * divisor <= number; divisor++)
        while (number % divisor == 0) {
            printf("%d ", divisor);
            number /= divisor;
        }
        
    if (number > 2)
        printf("%d ", number);
    printf("\n");

    Py_RETURN_NONE;
}

static PyObject *gcd(PyObject *self, PyObject *args)
{
  /*
  A funtion that returns the greatest common divisor of two numbers
  */  

  int first_number, second_number, remainder;

  if (!PyArg_ParseTuple(args, "ii", &first_number, &second_number));
      return NULL;
  
  while (second_number != 0) {
    remainder = first_number % second_number;
    first_number = second_number;
    second_number = remainder;
  }

  return PyLong_FromLong(first_number);
}

static PyObject *keyword_function(PyObject *self, PyObject *args, PyObject *keywds)
{
  /*
  This function demonstrates how to utalise multiple keyword inputs into a single C function
  It also shows how to take optional parameters in a function call. In the C parse function the | shows this.
  */

  int number;
  int second_optional_int = 1;
  int other_optional = 99;
  const char *word = "another optional one";
  
  static char *kwlist[] = {"number", "second_optional_int", "other_optional", "word", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "i|iis", kwlist, &number, &second_optional_int, &other_optional, &word))
    return NULL;

  printf("the value of first argument is: %d\n", number);
  printf("all the arguements in order: %d\n%d\n%d\n%s\n", number, second_optional_int, other_optional, word);

  Py_RETURN_NONE;
}

// static PyObject *vla_array(PyObject *self, PyObject *args)
// {
//     /*
//     A function that has an optional argument that determines how big the actual array is.
//     Otherwise we use the default value of 10.
//     */
//     int a[];
//     int default_value = 10;

//     if(!PyArg_ParseTuple(args, "a|i", &))
// }

static PyMethodDef ExtensionModuleMethods[] = {
    {"is_prime", is_prime, METH_VARARGS,
    "check if the given number is a prime number or not"},
    {"prime_factors", prime_factors, METH_VARARGS,
    "print out the prime factors for the given number"},
    {"gcd", gcd, METH_VARARGS,
     "return the greates comm divisor of 2 numbers"},
    {"keyword_function", keyword_function, METH_VARARGS,
     "demonstrates how to use couple of keywords"},
    {NULL, NULL, 0, NULL} // sentinel
};

static struct PyModuleDef extensionmodule = {
    PyModuleDef_HEAD_INIT,
    "extensionmodule",
    "",
    -1,
    ExtensionModuleMethods
};

PyMODINIT_FUNC PyInit_extensionmodule(void)
{
    return PyModule_Create(&extensionmodule);
}
