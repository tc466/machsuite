open_project knn_syn

add_files md.cpp
add_files -tb input.data
add_files -tb check.data
add_files -tb ../../common/harness.cpp

set_top md_kernel

open_solution -reset solution
set_part virtex7
create_clock -period 10
source ./knn_dir
#config_rtl -reset all -reset_level low
csynth_design
#cosim_design -rtl systemc -trace_level all

exit
