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
				bool drawn = false;
				if(bird.x == x && bird.y == y){
					cout << "O";
					drawn = true;
				}
				if(drawn == false){
					for(int i = 0; i < pipes.size(); i++){
						if(pipes[i].x == x){ // jesli jest tu rura, sprawdz czy dziura itp.
							if (y >= pipes[i].gapy && pipes[i].gapy + pipes[i].gapsize > y){
								cout << ".";
							}
							else{
								cout << "|";
							}
							drawn = true;
					}
					}
				}
				if(drawn == false){
					cout << ".";
				}
				}
				cout << endl;
			}
		}

void gameover(){
	cout << endl;
		cout << R"(  ######   #####  ###    ### #######      ######  ##    ## ####### ######  
 ##       ##   ## ####  #### ##          ##    ## ##    ## ##      ##   ## 
 ##   ### ####### ## #### ## #####       ##    ## ##    ## #####   ######  
 ##    ## ##   ## ##  ##  ## ##          ##    ##  ##  ##  ##      ##   ## 
  ######  ##   ## ##      ## #######      ######    ####   ####### ##   ## 
)";


}
bool is_running = true;
int main(){
	vector<Pipe> pipes;
	int randgap;
	int randsize;
	int framecounter = 0;
	string userchoice;
	int counter = 0;
	bool hit;
	Bird bird(5, 3);
	pipes.push_back(Pipe(69, 4, 3));
	pipes.push_back(Pipe(53, 6, 2));
	pipes.push_back(Pipe(39, 5, 4));


	while(is_running){ // uzycie wszystkich instrukcji do gry, glowna petla gry
	system("cls");

	srand(time(NULL));
	randgap = rand() % 15;
	randsize = rand() % 5 + 1;
	
	drawboard(bird, pipes);
	if(_kbhit()){
		char key;
		key = _getch();
		if(key == ' '){
			bird.jump();
			Sleep(40);
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
		
		gameover();

		is_running = false;
	}
	for(int i = 0; i < pipes.size(); i++){
		if(hit == false){
			if(bird.x == pipes[i].x){ // Warunek do hitboxa
				if(bird.y >= pipes[i].gapy && pipes[i].gapy + pipes[i].gapsize > bird.y){
					hit = false;
				}
				else{
					hit = true;
				}
			}
	}
		else{
			gameover();
			is_running = false;
		}
	}
	framecounter++;

	for(int i = 0; i < pipes.size(); i++){ // warunek do przesuniecia rury spowrotem w prawo
		if(pipes[i].x < 0){
			pipes[i].x = 69;
			pipes[i].gapy = randgap;
			pipes[i].gapsize = randsize;
		}
	}
	Sleep(50);
	}
}