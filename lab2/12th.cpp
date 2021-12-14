#include <iostream>

using namespace std;

template <typename T> void InsertionSort(T A[], int n) {
    int i, j;
    T pomocni;
    for (i = 0; i < n; i++) {
        pomocni = A[i];
        for (j = i; j >= 1 && pomocni < A[j-1]; j--) {
            A[j] = A[j-1];
        }
        A[j] = pomocni;
    }
}

class Osoba {
    string ime;
    unsigned short godine;
  public:
    Osoba() {};
    Osoba(string ime, unsigned short godine): ime(ime), godine(godine) {};
    string getIme() {
        return ime;
    }
    unsigned short getGodine() {
        return godine;
    }
    void setIme(string ime) {
        this->ime = ime;
    }
    void setGodine(unsigned short godine) {
        this->godine = godine;
    }
    friend bool operator< (const Osoba& o1, const Osoba& o2) {
        if (o1.godine == o2.godine) {
            if (o1.ime.compare(o2.ime) < 0) return true;
            return false;
        }
        return (o1.godine < o2.godine);
    }
};

int main (void) {
    Osoba polje[10];
    string ime;
    unsigned short godine;
    for (int i = 0; i < 10; i++) {
        cin >> ime >> godine;
        polje[i].setIme(ime);
        polje[i].setGodine(godine);
    }
    InsertionSort(polje, 10);
    for (int i = 0; i < 10; i++) {
        cout << polje[i].getIme() << " " << polje[i].getGodine() << endl;
    }
}