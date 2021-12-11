#include <iostream>
#include <ctime>

using namespace std;

class Stog {
    static const int MAX = 100;
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
};

int main (void) {
    Stog s;
    srand((unsigned)time(0));
    for (int i = 0; i < 101; i++) {
        cout << s.stavi(rand()%100);
    }
}