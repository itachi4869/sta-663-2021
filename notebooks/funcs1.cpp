#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int a, int b) {
    return a + b;
}

void init_f1(py::module &m) {
    m.def("add", &add);
}
