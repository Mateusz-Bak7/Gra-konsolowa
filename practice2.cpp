#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>

using namespace std;

class Bird{
public:
	int x;
	int y;
	Bird(int Startx, int Starty){
		x = Startx;
		y = Starty;
	}
	void jump(){
		y -= 2;
	}
	void print_position(){
		cout << "Pozycja ptaka: " << x << " " << y << endl;
	}
	void fall(){
		y ++;
	}
};

class Pipe{
public:
	int x;
	int gapy;
	int gapsize;
	Pipe(int startx, int startgap, int gap_size){
		x = startx;
		gapy = startgap;
		gapsize = gap_size;
	}
	void move(){
		x--;
	}
};

void drawboard(Bird bird, Pipe pipe){
		for(int y = 0; y < 15; y++){
			for(int x = 0; x < 70; x++){
				if(bird.x == x && bird.y == y){
					cout << "O";
				}
				else if(pipe.x == x){
					if(pipe.gapy <= y && pipe.gapy + pipe.gapsize > y){
						cout << ".";
						}
					else{
						cout << "|";
					}
				}
				else if(bird.x != x || bird.y != y){
					cout << ".";
				}
			}
			cout << endl;
		}
}

bool is_running = true;
int main(){
	vector<Pipe> pipes;
	int randgap;
	int randsize;
	int framecounter = 0;
	Bird bird(5, 3);
	pipes.push_back(Pipe(69, 4, 3));
	pipes.push_back(Pipe(53, 6, 2));
	pipes.push_back(Pipe(39, 5, 4));

	while(is_running){
	system("cls");

	srand(time(NULL));
	randgap = rand() % 15;
	randsize = rand() % 5;
	
	drawboard(bird, pipe);
	if(_kbhit()){
		char key;
		key = _getch();
		if(key == ' '){
			bird.jump();
		}
	}
	pipe.move();
	if(framecounter > 2){
	bird.fall();
	framecounter = 0;
	}
	if(bird.y > 15 || bird.y <= 0){
		
		cout << endl;
		cout << R"(  ######   #####  ###    ### #######      ######  ##    ## ####### ######  
 ##       ##   ## ####  #### ##          ##    ## ##    ## ##      ##   ## 
 ##   ### ####### ## #### ## #####       ##    ## ##    ## #####   ######  
 ##    ## ##   ## ##  ##  ## ##          ##    ##  ##  ##  ##      ##   ## 
  ######  ##   ## ##      ## #######      ######    ####   ####### ##   ## 
)";

		is_running = false;
	}
	if(bird.x == pipe.x && bird.x){ // Warunek do hitboxa
		if(pipe.gapy <= bird.y && pipe.gapy + pipe.gapsize > bird.y){
			continue;
		}
		else{
			cout << endl;
		cout << R"(  ######   #####  ###    ### #######      ######  ##    ## ####### ######  
 ##       ##   ## ####  #### ##          ##    ## ##    ## ##      ##   ## 
 ##   ### ####### ## #### ## #####       ##    ## ##    ## #####   ######  
 ##    ## ##   ## ##  ##  ## ##          ##    ##  ##  ##  ##      ##   ## 
  ######  ##   ## ##      ## #######      ######    ####   ####### ##   ## 
)";

			is_running == false;
			break;
		}
	}
	framecounter++;

	if(pipe.x < 0){
		pipe.x = 49;
		pipe.gapy = randgap;
		pipe.gapsize = randsize;
	}
	Sleep(50);
	}
}