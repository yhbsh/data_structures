

vis: run
	dot -Tpng ..\out\out1.dot -o ..\out\out1.png && ..\out\out1.png

run: heap
	..\exe\heap.exe

heap: heap.cpp
	g++ heap.cpp -o ../exe/heap.exe



clean:
	del ..\exe\*.exe ..\exe\*.png ..\out\*