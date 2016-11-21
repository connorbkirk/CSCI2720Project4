FILE = makeIn

compile:
	g++ -std=gnu++11 $(FILE).cpp

run:
	./a.out

clean:
	rm *.out
