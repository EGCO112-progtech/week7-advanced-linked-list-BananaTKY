compile: ll_example.c
	 gcc ll_example.c -o ll

compile2 : Assg7.c
	 gcc Assg7.c -o assg

run: ll
	 ./ll

run2 : assg
	 ./assg

clean: ll
	 rm ll
