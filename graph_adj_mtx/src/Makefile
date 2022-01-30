


vis: run
	dot -Tpng ..\output\out.dot -o ..\output\out.png && ..\output\out.png

run: main
	..\exe\main.exe

main: main.c
	gcc main.c -o ../exe/main.exe



clean:
	del ..\exe\*.exe ..\exe\*.png ..\output\*