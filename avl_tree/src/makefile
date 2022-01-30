
run: avl
	../exe/avl.exe

avl: avl.cpp
	g++ -o ../exe/avl.exe avl.cpp


vis:
	dot -Tpng ../out/out.dot -o ../out/out.png && ..\\out\\out.png

clean:
	del ..\\out\\*.dot ..\\out\\*.jpg ..\\exe\\*.exe