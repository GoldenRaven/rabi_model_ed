#.SILENT:
cc=g++
name=rabi_ed.x
objects=main.o rabi_basis.o date.o generate_basis.o globals.o input.o quant_num.o

#CPPFLAGS=-O0 -g
#CPPFLAGS=-O3
#MKL_FLAGS=-mkl=sequential
#OPENMP_FLAGS=-qopenmp

$(name): $(objects)
	$(cc) $(CPPFLAGS) $(MKL_FLAGS) $(OPENMP_FLAGS) -o $(name) $(objects) 

main.o: main.cpp 
	$(cc)  $(CPPFLAGS) -c main.cpp

rabi_basis.o: rabi_basis.cpp rabi_basis.h quant_num.h
	$(cc)  $(CPPFLAGS)  -c rabi_basis.cpp

quant_num.o: quant_num.cpp quant_num.h
	$(cc)  $(CPPFLAGS)  -c quant_num.cpp

date.o: date.cpp
	$(cc)  $(CPPFLAGS) -c date.cpp

input.o: input.cpp globals.h
	$(cc)  $(CPPFLAGS) -c input.cpp

generate_basis.o: generate_basis.cpp rabi_basis.h
	$(cc)  $(CPPFLAGS) -c generate_basis.cpp

clean:
	rm $(name) $(objects)

