#include <iostream>
using namespace std;

void display(){
	cout << R"(|#########################################################|)" << endl;
	cout << R"(|                                                      _  |)" << endl;
	cout << R"(|  ___ _                                 ___  _       | | |)" << endl;
	cout << R"(| | __| | __ _ _ __  _ __  _  _         | _ )(_)___  _| | |)" << endl;
	cout << R"(| | _|| |/ _` | '_ \| '_ \| || |        | _ \| |  _ / _`| |)" << endl;
	cout << R"(| |_| |_|\__,_| .__/| .__/\_, |         |___/|_|_|  \___| |)" << endl;
	cout << R"(|             |_|   |_|   |__/                            |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                         Opcje:                          |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                     1- Zasady gry                       |)" << endl;
	cout << R"(|                   2- Poziom trudności                   |)" << endl;
	cout << R"(|                      (In progress)                      |)" << endl;
	cout << R"(|                        3- Graj                          |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                   Autor: Mateusz Bak                    |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|#########################################################|)" << endl;
}

void rules(){
	cout << R"(|#########################################################|)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|         Gra jest oparta na klasycznym i znanym          |)" << endl;
	cout << R"(|            Flappy Birdzie. Trzeba manewrowac            |)" << endl;
	cout << R"(|        (skakac) ptaszkiem (litera O) tak, zeby          |)" << endl;
	cout << R"(|       nie uderzyc w podloge, szczyt mapy, albo          |)" << endl;
	cout << R"(|         rure. W rurach beda widoczne dziury.            |)" << endl;
	cout << R"(|     Wlasnie w te dziury trzeba wleciec ptaszkiem,       |)" << endl;
	cout << R"(|      aby moc grac dalej i zyskac +1 punkt. I tak        |)" << endl;
	cout << R"(|      gramy dopoki nie zderzymy sie z wspomnianymi       |)" << endl;
	cout << R"(|       wczesniej obiektami. Mozna zmienic poziom         |)" << endl;
	cout << R"(|       trudnosci (lat. sred. trud.). Powodzenia!         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|          Wcisn. dowolny klawisz, aby wyjsc.             |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|#########################################################|)" << endl;
}

void difficulty(){
	cout << R"(|#########################################################|)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|          ___  _  __  __ _            _ _                |)" << endl;
	cout << R"(|         |   \(_)/ _|/ _(_)__ _  _  _| | |_ _  _         |)" << endl;
	cout << R"(|         | |) | |  _|  _| / _| || || | |  _| || |        |)" << endl;
	cout << R"(|         |___/|_|_| |_| |_\___\_,,_|_|_|\__|\_, |        |)" << endl;
	cout << R"(|                                            |__/         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                        1 - EASY                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                       2 - MEDIUM                        |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                        3 - HARD                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                        E = Exit                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|                                                         |)" << endl;
	cout << R"(|#########################################################|)" << endl;
}
int main(){
	display();
}