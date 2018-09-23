#.SILENT:
cc=icpc
name=rabi_ed.x
objects=main.o rabi_basis.o date.o globals.o input.o output.o quant_num.o operator.o hamilt.o

#CPPFLAGS=-O0 -g
#CPPFLAGS=-O3
MKL_FLAGS=-mkl=sequential
OPENMP_FLAGS=-qopenmp

$(name): $(objects)
	$(cc) $(CPPFLAGS) $(MKL_FLAGS) $(OPENMP_FLAGS) -o $(name) $(objects)

main.o: main.cpp
	$(cc)  $(CPPFLAGS) -c main.cpp

globals.o: globals.cpp globals.h
	$(cc)  $(CPPFLAGS)  -c globals.cpp

rabi_basis.o: rabi_basis.cpp rabi_basis.h quant_num.h
	$(cc)  $(CPPFLAGS)  -c rabi_basis.cpp

quant_num.o: quant_num.cpp quant_num.h
	$(cc)  $(CPPFLAGS)  -c quant_num.cpp

date.o: date.cpp
	$(cc)  $(CPPFLAGS) -c date.cpp

input.o: input.cpp globals.h
	$(cc)  $(CPPFLAGS) -c input.cpp

output.o: output.cpp globals.h
	$(cc)  $(CPPFLAGS) -c output.cpp

operator.o: operator.cpp globals.h rabi_basis.h operator.h
	$(cc)  $(CPPFLAGS) -c operator.cpp

hamilt.o: hamilt.cpp globals.h rabi_basis.h hamilt.h
	$(cc)  $(CPPFLAGS) -c hamilt.cpp

clean:
	rm $(name) $(objects)
