all: Scheduler.out

Scheduler.out: main.o functions.o
	g++ main.o functions.o -o Scheduler.out

main.o: main.cpp functions.h core_class.h process_class.h thread_class.h
	g++ -c main.cpp

functions.o: functions.cpp functions.h core_class.h process_class.h thread_class.h
	g++ -c functions.cpp


.PHONY: clean
clean:
	rm *.o 
	rm Scheduler.out