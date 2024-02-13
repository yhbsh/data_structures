all: queue run clean

clean: run
	rm queue

run: queue
	./queue


queue: queue.c
	cc queue.c -o queue
