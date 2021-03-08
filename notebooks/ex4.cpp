#include "funcs.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(ex4, m) {
    m.def("add", &add);
    m.def("mult", &mult);
}
