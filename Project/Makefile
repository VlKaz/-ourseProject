all: report.exe
report.exe: report.o temp_function.o
	gcc -o report report.o temp_function.o
report.o: report.c temp_function.h
	gcc -c --std=c99 -o report.o report.c
temp_function.o: temp_function.c
	gcc -c --std=c99 -o temp_function.o temp_function.c
clean:
	del *.o
	del report.exe

