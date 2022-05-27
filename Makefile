main: main.cpp display.cpp window.cpp paramsinput.cpp engine.cpp paramsinput.h engine.h
	g++ main.cpp display.cpp window.cpp paramsinput.cpp engine.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`

run: main
	./main

clean:
	rm main