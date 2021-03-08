<%
setup_pybind11(cfg)
%>
#include <pybind11/pybind11.h>
namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_MODULE(ex2, m) {
    m.def("add", 
          [](int a, int b) { return a + b; },
          "Add two integers.",
          py::arg("a") = 3, 
          py::arg("b") = 4);
    m.def("mult", 
          [](int a, int b) { return a * b; },
          "Multiply two integers.",
          "a"_a=3, 
          "b"_a=4);
}
