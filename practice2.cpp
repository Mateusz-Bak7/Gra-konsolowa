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


int main(){
	Bird bird(5, 3);

	while(true){
	system("cls");
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 20; x++){
			if (bird.x != x || bird.y != y){
				cout << ".";
			}
			else{
				cout << "O";
			}
		}
		cout << endl;
	}
	bird.fall();
	
	Sleep(1000);
}
system("cls");
}