all:  build run clean

build:
	@echo "Compiling the required files....."
	
	gcc Main_Program.c -o Main_Program
	gcc cat.c -o cat
	gcc tac.c -o tac
	gcc ls_l.c -o ls_l
	gcc ls_a.c -o ls_a
	gcc mkdir.c -o mkdir
	gcc mkdir_v.c -o mkdir_v
	gcc rm.c -o rm
	gcc rm_i.c -o rm_i
	gcc date1.c -o date1
	gcc date2.c -o date2
	
run:	
	@echo "Executing the main program....."
	
	./Main_Program
	
clean: 
	@echo "Removing all the binary files created during the execution....."
	
	rm Main_Program cat tac ls_l ls_a mkdir mkdir_v rm rm_i date1 date2 	


