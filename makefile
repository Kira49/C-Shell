shell: \
			first.o \
			inputProcessing.o \
			execute.o \
			errorHandling.o \
			ls.o \
			invoke.o \
			paths.o \
			cd.o \
			pwd.o \
			echo.o \
			pinfo.o \
			bg.o \

	gcc -g -o shell $^


clean:
	@rm -f *.o shell

first.o:  header.h
	gcc -g -c first.c

inputProcessing.o:  header.h
	gcc -g -c inputProcessing.c

execute.o:  header.h
	gcc -g -c execute.c

errorHandling.o:  header.h
	gcc -g -c errorHandling.c

ls.o:  header.h
	gcc -g -c ls.c

paths.o: header.h
	gcc -g -c paths.c

pinfo.o:  header.h
	gcc -g -c  pinfo.c

bg.o: header.h
	gcc -g -c bg.c

invoke.o: header.h
	gcc -g -c invoke.c

cd.o:  header.h
	gcc -g -c cd.c

pwd.o:  header.h
	gcc -g -c pwd.c

echo.o:  header.h
	gcc -g -c echo.c
