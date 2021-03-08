/*
<%
cfg['compiler_args'] = ['-std=c++11', '-fopenmp']
cfg['linker_args'] = ['-lgomp']
setup_pybind11(cfg)
%>
*/
#include <cmath>
#include <omp.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

// Passing in an array of doubles
void twice(py::array_t<double> xs) {
    py::gil_scoped_acquire acquire;
    
    py::buffer_info info = xs.request();
    auto ptr = static_cast<double *>(info.ptr);

    int n = 1;
    for (auto r: info.shape) {
      n *= r;
    }

    #pragma omp parallel for
    for (int i = 0; i <n; i++) {
        *ptr++ *= 2;
    }
}  

PYBIND11_MODULE(ex9, m) {
  m.doc() = "auto-compiled c++ extension";
  m.def("twice", [](py::array_t<double> xs) {
      /* Release GIL before calling into C++ code */      
      py::gil_scoped_release release;
      return twice(xs);
    });
}
