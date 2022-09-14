set(P_CB_2017_SOURCES P_cb/emu.h P_cb/emu.c P_cb/params.h)
add_library(P_CB_2017_LIB ${P_CB_2017_SOURCES})
target_include_directories(P_CB_2017_LIB PUBLIC P_cb)
target_link_libraries(P_CB_2017_LIB PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_CB_2017_LIB PROPERTIES OUTPUT_NAME emu_Pcb)

add_executable(P_CB_2017 P_cb/main.c)
target_link_libraries(P_CB_2017 PRIVATE  P_CB_2017_LIB)
set_target_properties(P_CB_2017 PROPERTIES OUTPUT_NAME emu_Pcb)

if(PYTHON_LIBRARY)
    pybind11_add_module(P_CB_2017_PY P_cb/pyemu.cpp)
    target_link_libraries(P_CB_2017_PY PRIVATE P_CB_2017_LIB)
    set_target_properties(P_CB_2017_PY PROPERTIES OUTPUT_NAME _emu_2017_cb)
endif()


set(P_TOT_2017_SOURCES P_tot/emu.c P_tot/params.h)
add_library(P_TOT_2017_LIB ${P_TOT_2017_SOURCES})
target_include_directories(P_TOT_2017_LIB PUBLIC P_tot)
target_link_libraries(P_TOT_2017_LIB PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_TOT_2017_LIB PROPERTIES OUTPUT_NAME emu_Ptot)

add_executable(P_TOT_2017 P_tot/main.c)
target_link_libraries(P_TOT_2017 PRIVATE P_TOT_2017_LIB)
set_target_properties(P_TOT_2017 PROPERTIES OUTPUT_NAME emu_Ptot)

if(PYTHON_LIBRARY)
    pybind11_add_module(P_TOT_2017_PY P_tot/pyemu.cpp)
    target_link_libraries(P_TOT_2017_PY PRIVATE P_TOT_2017_LIB)
    set_target_properties(P_TOT_2017_PY PROPERTIES OUTPUT_NAME _emu_2017_tot)
endif()
