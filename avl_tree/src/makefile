
vis: run
	dot -Tjpeg ../out/out.dot -o ../out/out.jpeg && open ../out/out.jpeg



run: avl
	../run/avl

avl: avl.cpp
	g++-12 -o ../run/avl avl.cpp

