<%
cfg['compiler_args'] = ['-std=c++11']
setup_pybind11(cfg)
%>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

// Passing in an array of doubles
void twice(py::array_t<double> xs) {
    py::buffer_info info = xs.request();
    auto ptr = static_cast<double *>(info.ptr);

    int n = 1;
    for (auto r: info.shape) {
      n *= r;
    }

    for (int i = 0; i <n; i++) {
        *ptr++ *= 2;
    }
}

// Passing in a generic array
double sum(py::array xs) {
    py::buffer_info info = xs.request();
    auto ptr = static_cast<double *>(info.ptr);

    int n = 1;
    for (auto r: info.shape) {
      n *= r;
    }

    double s = 0.0;
    for (int i = 0; i <n; i++) {
        s += *ptr++;
    }

    return s;
}

PYBIND11_MODULE(ex7, m) {
    m.doc() = "auto-compiled c++ extension";
    m.def("sum", &sum);
    m.def("twice", &twice);
}
