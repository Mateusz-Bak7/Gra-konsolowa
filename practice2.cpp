#include <iostream>
#include <windows.h>
#include <conio.h>

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
	Pipe(int startx){
		x = startx;
	}
	void move(){
		x--;
	}
};

void drawboard(Bird bird, Pipe pipe){
		for(int y = 0; y < 15        ; y++){
			for(int x = 0; x < 70; x++){
				if(bird.x == x && bird.y == y){
					cout << "O";
				}
				else if(pipe.x == x){
					cout << "|";
				}
				else if(bird.x != x || bird.y != y){
					cout << ".";
				}
			}
			cout << endl;
		}
	}

int main(){
	int framecounter = 0;
	bool is_running = true;
	Bird bird(5, 3);
	Pipe pipe(19);

	while(is_running){
	system("cls");
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

		cout << R"(  ######   #####  ###    ### #######      ######  ##    ## ####### ######  
 ##       ##   ## ####  #### ##          ##    ## ##    ## ##      ##   ## 
 ##   ### ####### ## #### ## #####       ##    ## ##    ## #####   ######  
 ##    ## ##   ## ##  ##  ## ##          ##    ##  ##  ##  ##      ##   ## 
  ######  ##   ## ##      ## #######      ######    ####   ####### ##   ## 
)";

		is_running = false;
	}
	framecounter++;
	Sleep(50);
	}
}