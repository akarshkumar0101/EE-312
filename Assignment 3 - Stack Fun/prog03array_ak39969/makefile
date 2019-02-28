# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 


driver: driver.o stack_arr.o
	c99 -o driver driver.o stack_arr.o
driver.o: driver.c
	c99 -c driver.c
stack_arr.o: stack_arr.c
	c99 -c stack_arr.c
