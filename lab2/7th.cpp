#include <iostream>

using namespace std;

struct Cvor {
    double broj;
    Cvor *sljedeci;
};

class Red {
    Cvor* ulaz = nullptr;
    Cvor* izlaz = nullptr;
  public:
    bool dodaj (double broj) {
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
    bool skini (double *broj) {
        if (izlaz == nullptr) return false;
        *broj = izlaz->broj;
        Cvor *zaBrisanje = izlaz;
        izlaz = izlaz->sljedeci;
        if (izlaz == nullptr) ulaz = nullptr;
        delete zaBrisanje;
        return true;
    }
};

int main (void) {
    Red r;
    double a;
    for (int i = 0; i < 10; i++) {
        cin >> a;
        r.dodaj(a);
    }
    while(r.skini(&a)) cout << a << " ";
}