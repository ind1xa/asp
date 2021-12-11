#include <iostream>

using namespace std;

class Red {
    static const int MAX = 10;
    double red[MAX];
    int ulaz = 0;
    int izlaz = 0;
  public:
    bool dodaj (double broj) {
        if ((ulaz + 1) % MAX == izlaz) return false;
        red[ulaz] = broj;
        ulaz = (ulaz + 1) % MAX;
        return true;
    }
    bool skini (double *broj) {
        if (ulaz == izlaz) return false;
        *broj = red[izlaz];
        izlaz = (izlaz + 1) % MAX;
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