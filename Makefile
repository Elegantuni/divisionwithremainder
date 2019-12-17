divisionwithremainder1:
	g++ -o divisionwithremainder1 main.cpp `pkg-config --cflags --libs ncurses`

clean:
	rm -f divisionwithremainder1

