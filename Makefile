all:
	g++ -o main main.cpp allSort.cpp -Wall -g
clean:
	rm main *~ -rf
