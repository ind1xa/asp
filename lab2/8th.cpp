#include <iostream>

using namespace std;

struct Cvor {
    int broj;
    Cvor *sljedeci;
};

class Red {
    Cvor* ulaz = nullptr;
    Cvor* izlaz = nullptr;
  public:
    bool dodaj (int broj) {
        Cvor* novi = new Cvor;
        if (novi == nullptr) return false;
        novi->broj = broj;
        novi->sljedeci = nullptr;
        if (ulaz == nullptr) {
            izlaz = novi;
        } else {
            ulaz->sljedeci = novi;
        }
        ulaz = novi;
        return true;
    }
    bool poljeURed (int polje[], int n) {
        if (n == 0) return true;
        if (!dodaj(polje[n-1])) return false;
        cout << polje[n-1] << " ";
        poljeURed(polje, n-1);
    }
};

int main (void) {
    Red r;
    int polje[10];
    srand((unsigned)time(0));
    for (int i = 0; i < 10; i++) {
        polje[i] = rand()%10 + 1;
        cout << polje[i] << " ";
    }
    cout << endl;
    r.poljeURed(polje, 10);
}