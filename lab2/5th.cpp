#include <iostream>
#include <ctime>

using namespace std;

class Stog {
    static const int MAX = 10;
    int stog[MAX];
    int vrh = -1;
  public: 
    bool stavi(int element) {
        if (vrh < MAX-1) {
            stog[++vrh] = element;
            return true;
        } else {
            return false;
        }
    }
    bool uzmi(int &element) {
        if (vrh == -1) return false;
        element = stog[vrh--];
        return true;
    }
};

int main (void) {
    Stog s;
    int a;
    srand((unsigned)time(0));
    for (int i = 0; i < 10; i++) {
        a = rand()%10 + 1;
        s.stavi(a);
        //cout << a;
    }
    Stog pomocni;
    for (int i = 0; i < 10; i++) {
        if (s.uzmi(a)) pomocni.stavi(a);
    }
    //cout << endl;
    for (int i = 0; i < 10; i++) {
        if (pomocni.uzmi(a)) cout << a << " ";
    }
}