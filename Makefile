a.out: main.o skorowidz.o 
	$(CC) $^

main.o: skorowidz.h
skorowidz.o: skorowidz.h

