main: main.cpp display.cpp window.cpp paramsinput.cpp config.cpp engine.cpp paramsinput.h config.h engine.h
	g++ main.cpp display.cpp window.cpp paramsinput.cpp config.cpp engine.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`

run: main
	./main

clean:
	rm main