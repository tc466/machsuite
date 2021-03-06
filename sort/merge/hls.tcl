open_project merge_syn

add_files merge.c
add_files input.data
add_files check.data
add_files -tb ../../common/harness.c

set_top mergesort

open_solution -reset solution
set_part virtex7
create_clock -period 10
source ./merge_dir
csynth_design
cosim_design -rtl systemc -trace_level all

exit
