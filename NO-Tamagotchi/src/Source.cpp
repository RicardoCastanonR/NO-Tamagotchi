#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define _UP		72
#define _LEFT	75
#define _RIGTH	77
#define _DOWN	80

void moveUp() {
	std::cout << "\033[F";
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

int main() {
	std::cout << "Starting a new project!" << std::endl;
	
	clock_t global_time = clock();
	clock_t current_time;
	current_time = clock();
	clock_t elapsed = clock() - current_time;
	
	while (true) {
		elapsed = clock() - current_time;
		if ( (float)elapsed >= CLOCKS_PER_SEC / 60) {
			moveUp();
			moveUp();
			eraseLine();
			clock_t global_time_elapsed = clock() - global_time;
			std::cout << "Elapsed time: " << ((float)global_time_elapsed) / CLOCKS_PER_SEC << std::endl;
			
			std::cout << (float)elapsed / CLOCKS_PER_SEC << std::endl;
			current_time = clock();
			input();
		}
		
	}
	return 0;
}

