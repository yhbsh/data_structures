

vis: run
	dot -Tpng ..\out\out.dot -o ..\out\out.png && ..\out\out.png

run: bst
	..\exe\bst.exe

bst: bst.cpp
	g++ bst.cpp -o ../exe/bst.exe



clean:
	del ..\exe\*.exe ..\exe\*.png ..\out\*