open_project rsa_syn

add_files rsa.c
add_files input.data
add_files check.data
add_files -tb ../../common/harness.c

#add_files -tb rsa_test.c

set_top rsa_decrypt

open_solution -reset solution
set_part virtex7
create_clock -period 10
#source ./rsa_dir
#config_rtl -reset all -reset_level low
csynth_design
cosim_design -rtl systemc -trace_level all

exit
