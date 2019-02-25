# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 


equation_checker: equation_checker.o stack_arr.o
	c99 -o equation_checker equation_checker.o stack_arr.o
equation_checker.o: equation_checker.c
	c99 -c equation_checker.c

flood_fill: flood_fill.o stack_ll.o
	c99 -o flood_fill flood_fill.o stack_ll.o
flood_fill.o: flood_fill.c
	c99 -c flood_fill.c

test_stack_arr: stack_arr.o test_stack_arr.o test_stack_ll
	c99 -o test_stack_arr stack_arr.o test_stack_arr.o
stack_arr.o: stack_arr.c
	c99 -c stack_arr.c
test_stack_arr.o: test_stack_arr.c
	c99 -c test_stack_arr.c

test_stack_ll: stack_ll.o test_stack_ll.o
	c99 -o test_stack_ll stack_ll.o test_stack_ll.o
stack_ll.o: stack_ll.c
	c99 -c stack_ll.c
test_stack_ll.o: test_stack_ll.c
	c99 -c test_stack_ll.c
