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
				else if(for(int i = 0; i < pipes.size(); i++)){
					if(for(int i = 0; pipes.size(); i++)){
						if(pipes.gapy <= y && pipes.gapy + pipes.gapsize > y){
							cout << ".";
							}
						else{
							cout << "|";
						}
						
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
	int userchoice;
	int counter = 0;
	Bird bird(5, 3);
	pipes.push_back(Pipe(69, 4, 3));
	pipes.push_back(Pipe(53, 6, 2));
	pipes.push_back(Pipe(39, 5, 4));

	display();
	cin >> userchoice;
	switch(userchoice){
		case 1:
			rules();
			if (_kbhit()){
				main();
				break;
			}
		case 2:
			difficulty();
			userchoice = _getch();
			if(userchoice == '1'){

			}
			else if(userchoice == '2'){

			}
			else if(userchoice == '3'){

			}
			else if(userchoice == 'E'){
				main();
			}
			else{
				cout << "Niepoprawna opcja. Sprobuj ponownie." << endl;
			}
		case 3:
			break;
			main();	
		default:
			cout << "Nie ma takiej opcji. Wybierz ponownie." << endl;
			Sleep(2000);
			main();
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
	pipes.move();
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