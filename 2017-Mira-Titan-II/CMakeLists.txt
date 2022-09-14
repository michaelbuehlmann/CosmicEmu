set(P_CB_SOURCES P_cb/emu.c P_cb/params.h)
add_executable(P_CB_2017 ${P_CB_SOURCES})
target_link_libraries(P_CB_2017 PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_CB_2017 PROPERTIES OUTPUT_NAME P_cb)

set(P_TOT_SOURCES P_tot/emu.c P_tot/params.h)
add_executable(P_TOT_2017 ${P_TOT_SOURCES})
target_link_libraries(P_TOT_2017 PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_TOT_2017 PROPERTIES OUTPUT_NAME P_tot)