#include <iostream>

using namespace std;

template <class T>
struct cvor {
    T element;
    cvor* prethodni;
    cvor* sljedeci;
};

template <class T>
class Lista {
    cvor<T>* glava = nullptr;
  public:  
    bool upis (T element) {
        cvor<T>* novi = new cvor<T>; 
        if (novi == nullptr) return false;
        novi->element = element;
        if (!glava) { 
            novi->sljedeci = nullptr;
            novi->prethodni = nullptr;
            glava = novi;
        } else {
            cvor<T>* trenutni;
            for (trenutni = glava; trenutni->sljedeci; trenutni = trenutni->sljedeci);
            trenutni->sljedeci = novi;
            novi->sljedeci = nullptr;
            novi->prethodni = trenutni;
        }
        return true;
    }
    void ispis() {
        cvor<T>* trenutni ;
        for(trenutni = glava; trenutni; trenutni = trenutni->sljedeci) {
            cout << trenutni->element << " ";
        }
    }
};

int main (void) {
    string a;
    Lista<string> lista;
    for (int i = 0; i < 10; i++) {
        cin >> a;
        lista.upis(a);
    }
    lista.ispis();
}