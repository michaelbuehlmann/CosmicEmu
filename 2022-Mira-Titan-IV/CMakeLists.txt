set(P_CB_2022_SOURCES P_cb/emu.h P_cb/emu.c P_cb/params.h)
add_library(P_CB_2022_LIB ${P_CB_2022_SOURCES})
target_include_directories(P_CB_2022_LIB PUBLIC P_cb)
target_link_libraries(P_CB_2022_LIB PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_CB_2022_LIB PROPERTIES OUTPUT_NAME emu_Pcb)

add_executable(P_CB_2022 P_cb/main.c)
target_link_libraries(P_CB_2022 PRIVATE  P_CB_2022_LIB)
set_target_properties(P_CB_2022 PROPERTIES OUTPUT_NAME emu_Pcb)


set(P_TOT_2022_SOURCES P_tot/emu.c P_tot/params.h)
add_library(P_TOT_2022_LIB ${P_TOT_2022_SOURCES})
target_include_directories(P_TOT_2022_LIB PUBLIC P_tot)
target_link_libraries(P_TOT_2022_LIB PRIVATE GSL::gsl GSL::gslcblas m)
set_target_properties(P_TOT_2022_LIB PROPERTIES OUTPUT_NAME emu_Ptot)

add_executable(P_TOT_2022 P_tot/main.c)
target_link_libraries(P_TOT_2022 PRIVATE P_TOT_2022_LIB)
set_target_properties(P_TOT_2022 PROPERTIES OUTPUT_NAME emu_Ptot)