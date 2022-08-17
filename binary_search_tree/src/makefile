

vis: run
	dot -Tjpeg ../out/out.dot -o ../out/out.jpeg && open ../out/out.jpeg

run: bst
	../run/bst

bst: bst.cpp
	g++-12 bst.cpp -o ../run/bst



clean:
	rm -r ../run/ ../out/ 