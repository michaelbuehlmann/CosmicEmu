#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

extern "C" {
    // defines
    // void emu(double *xstar, double *ystar);
    #include "emu.h"
}
namespace py = pybind11;

py::array py_emu(
    double omega_m,
    double omega_b,
    double sigma_8,
    double h,
    double n_s,
    double w_0,
    double w_a,
    double omega_nu) {

    double xstar[9] = {omega_m, omega_b, sigma_8, h, n_s, w_0, w_a, omega_nu};
    // allocate array in fortran order so that elements in column are consecutive
    py::array_t<double, py::array::f_style> kpk({nmode, 2}, {8});

    // fill k
    for(int i=0; i<nmode; ++i) {
        kpk.mutable_data()[i] = mode[i];
    }
    // get P(k) from emulator
    emu(xstar, kpk.mutable_data()+nmode);

    return kpk;
}

PYBIND11_MODULE(emu_2022_cb, m) {
    m.doc() = "Mira-Tita-IV (2022) P_cb emulator";
    m.def(
        "emu", &py_emu,
        py::arg("omega_m"), py::arg("omega_b"), py::arg("sigma_8"),
        py::arg("h"), py::arg("ns"), py::arg("w_0"), py::arg("w_a"),
        py::arg("omega_nu"));
}