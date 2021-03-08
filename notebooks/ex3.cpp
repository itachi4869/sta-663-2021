
<%
setup_pybind11(cfg)
cfg['sources'] = ['funcs1.cpp', 'funcs2.cpp']
%>
#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_f1(py::module &m);
void init_f2(py::module &m);

PYBIND11_MODULE(ex3, m) {
    init_f1(m);
    init_f2(m);
}
