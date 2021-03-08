<%
cfg['compiler_args'] = ['-std=c++14'] 
setup_pybind11(cfg)
%>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
double square(double x) {
    return x * x;
}

PYBIND11_MODULE(ex6, m) {
    m.doc() = "pybind11 example plugin";
    m.def("square", py::vectorize(square), "A vectorized square function.");
}
