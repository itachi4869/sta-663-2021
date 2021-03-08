<%
cfg['compiler_args'] = ['-std=c++11']
cfg['include_dirs'] = ['../notebooks/eigen3']
setup_pybind11(cfg)
%>

#include <math.h>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/LU>

namespace py = pybind11;

Eigen::VectorXd logistic(Eigen::VectorXd xs) {
    return 1 - 1 / (1 + exp(xs.array()));
}
    
PYBIND11_MODULE(logistic_gd, m) {
    m.doc() = "auto-compiled c++ extension";
    m.def("logistic", &logistic);
}
