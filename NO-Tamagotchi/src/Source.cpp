#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define HEIGHT	32
#define WIDTH	32

#define _UP		72
#define _LEFT	75
#define _RIGTH	77
#define _DOWN	80

const int MAX_HEALT = 100;

void moveUp() {
	std::cout << "\033[F";
}

void moveDown() {
	std::cout << "\033[E";
}

void moveRight() {
	std::cout << " ";
}

void eraseLine() {
	std::cout << "\033[K";
}

void input() {
	if (_kbhit()) {
		int c;
		c = _getch();
		//std::cin >> c;
		//std::cout << "The presed key is: " << c;
		if (c == _UP)
			std::cout << "UP arrow has been pressed";
		if (c == _DOWN)
			std::cout << "DOWN arrow has been pressed";
		if (c == _LEFT)
			std::cout << "LEFT arrow has been pressed";
		if (c == _RIGTH)
			std::cout << "RIGTH arrow has been pressed";
	}
}

void clearScreen() {
	for (int i = 0; i < HEIGHT; i++) {
		eraseLine();
		moveUp();
	}
}

void addOfset(int x_offset, int y_offset) {
	for (int i = 0; i < y_offset; i++) {
		moveDown();
		for (int j = 0; j < x_offset; j++) {
			moveRight();
		}
	}
}

void renderHealthBar(int health, int x_offset, int y_offset) {
	addOfset(x_offset, y_offset);
	std::cout << "HEALTH [";
	for (int i = 0; i <= (health / 10); i++)
		std::cout << "#";

	for (int i = 0; i <= (MAX_HEALT-health) / 10; i++)
		std::cout << " ";

	std::cout << "]";
}

void draw() {
	return;
}

int main() {
	std::cout << "Starting a new project!" << std::endl;
	
	clock_t global_time = clock();
	clock_t current_time;
	current_time = clock();
	clock_t elapsed = clock() - current_time;
	
	while (true) {
		elapsed = clock() - current_time;
		if ( (float)elapsed >= CLOCKS_PER_SEC / 60) {
			clearScreen();
			clock_t global_time_elapsed = clock() - global_time;
			
			std::cout << "Elapsed time: " << ((float)global_time_elapsed) / CLOCKS_PER_SEC << std::endl;

			renderHealthBar(90, 0, 2);
			
			std::cout << (float)elapsed / CLOCKS_PER_SEC << std::endl;
			current_time = clock();
			input();
		}
		
	}
	return 0;
}

