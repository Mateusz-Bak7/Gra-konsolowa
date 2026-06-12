#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>
#include "testmenu.cpp"

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

void drawboard(Bird bird, vector<Pipe> pipes){
		for(int y = 0; y < 15; y++){
			for(int x = 0; x < 70; x++){
				if(bird.x == x && bird.y == y){
					cout << "O";
				}
				else if(bird.x != x || bird.y != y){
					cout << ".";
				}
				else{
					for(int i = 0; i < pipes.size(); i++){
						for(int i = 0; i < pipes.size(); i++){
							if(y <= pipes[i].gapy && pipes[i].gapy + pipes[i].gapsize > y){
								cout << ".";
							}
							else{
								cout << "|";
							}
						}
					}
				}
			}
			cout << endl;
			}
		}

bool is_running = false;
int main(){
	vector<Pipe> pipes;
	int randgap;
	int randsize;
	int framecounter = 0;
	string userchoice;
	int counter = 0;
	Bird bird(5, 3);
	pipes.push_back(Pipe(69, 4, 3));
	pipes.push_back(Pipe(53, 6, 2));
	pipes.push_back(Pipe(39, 5, 4));

	display();
	cin >> userchoice;
	if(userchoice == "3"){
		is_running = true;
	}

	while(is_running){
	system("cls");

	srand(time(NULL));
	randgap = rand() % 15;
	randsize = rand() % 5;
	
	drawboard(bird, pipes);
	if(_kbhit()){
		char key;
		key = _getch();
		if(key == ' '){
			bird.jump();
		}
	}
	for(int i = 0; i < pipes.size(); i++){
		pipes[i].move();
	}
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
	for(int i = 0; i < pipes.size(); i++){
	if(bird.x == pipes[i].x && bird.x){ // Warunek do hitboxa
		if(pipes[i].gapy <= bird.y && pipes[i].gapy + pipes[i].gapsize > bird.y){
			break;
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
	}
	framecounter++;

	for(int i = 0; i < pipes.size(); i++){
		if(pipes[i].x < 0){
			pipes[i].x = 49;
			pipes[i].gapy = randgap;
			pipes[i].gapsize = randsize;
		}
	}
	Sleep(50);
	}
}