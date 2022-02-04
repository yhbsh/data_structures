


vis: run
	dot -Tjpg ..\output\out.dot -o ..\output\out.jpg && ..\output\out.jpg

run: main
	..\exe\main.exe

main: main.c
	gcc main.c -o ../exe/main.exe



clean:
	del ..\exe\*.exe ..\exe\*.jpg ..\output\*