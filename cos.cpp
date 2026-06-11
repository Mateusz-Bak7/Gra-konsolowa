#include <iostream>
#include <string>
using namespace std;
class Bird{
    public:
        Bird(string size, string color) {}

        void fly(){
            cout << "im flying" << endl;
        }
};
int main(){
    Bird flappy_bird("big", "red");
    flappy_bird.fly();
}