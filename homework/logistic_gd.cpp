<%
cfg['compiler_args'] = ['-std=c++11']
cfg['include_dirs'] = ['../notebooks/eigen3']
setup_pybind11(cfg)
%>

#include <cmath>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/LU>

namespace py = pybind11;
using namespace Eigen;

VectorXd logistic(VectorXd xs) {
    return 1 - 1 / (1 + exp(xs.array()));
}

MatrixXd gd(MatrixXd X, VectorXd y, VectorXd beta, double alpha, int niter) {
    
    int i = 0, n, p;
    MatrixXd Xt;
    VectorXd y_pred, epsilon, grad;
    
    n = X.rows();
    p = X.cols();
    Xt = X.transpose();
    y_pred = VectorXd::Zero(n);
    epsilon = VectorXd::Zero(n);
    grad = VectorXd::Zero(p);
    
    for(i = 0; i < niter; i++) {
        y_pred = logistic(X * beta);
        epsilon = y - y_pred;
        grad = Xt * epsilon / n;
        beta += alpha * grad;
    }
    
    return beta;
}
    
PYBIND11_MODULE(logistic_gd, m) {
    m.doc() = "auto-compiled c++ extension";
    m.def("logistic", &logistic);
    m.def("gd", &gd);
}
