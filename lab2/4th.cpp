#include <iostream>
#include <ctime>

using namespace std;

class Stog {
    static const size_t uvecanje = 100;
    size_t velicina = 100;
    int *stog;
    int vrh = -1;
  public: 
    Stog() { stog = (int *)malloc(velicina * sizeof(int)); }
    Stog(size_t velicina) : velicina(velicina) { stog = (int *)malloc(velicina * sizeof(int)); }
    bool stavi(int element) {
        if (vrh >= velicina-1) {
            int *pomocni = (int *)realloc(stog, velicina + uvecanje);
            if (!pomocni)
                return false;
            stog = pomocni;
            velicina += uvecanje;
        }
        stog[++vrh] = element;
        return true;
    }
};

int main (void) {
    Stog s;
    srand((unsigned)time(0));
    for (int i = 0; i < 101; i++) {
        cout << s.stavi(rand()%100);
    }
}