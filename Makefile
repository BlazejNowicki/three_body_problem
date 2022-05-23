main: main.cpp window.cpp
	g++ main.cpp window.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`

run: main
	./main

clean:
	rm main