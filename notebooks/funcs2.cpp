#include <pybind11/pybind11.h>
namespace py = pybind11;

int mult(int a, int b) {
    return a + b;
}

void init_f2(py::module &m) {
    m.def("mult", &mult);
}
