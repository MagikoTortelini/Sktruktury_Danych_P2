#ifndef tablica_dynamiczna_hpp
#define tablica_dynamiczna_hpp
#include <iostream>

using namespace std;

template <typename T>
class Tablica_dynamiczna{
    private:
        T* tab;
        int size;
        // aktualna ilosc elementow
        int actual;
    public: 
        // konstruktor i desktruktor
        Tablica_dynamiczna(int s){actual = 0; size = s; tab = new T[size];};
        ~Tablica_dynamiczna() {
            for(int i=0;i<actual-1;i++){
                delete tab[i];
            }
        };

        T& get(int index){
            return tab[index];
        }

        int get_size(){
            return actual;
        }
        int resize() {
            // powiekszenie rozmiaru dwukrotnie
            int n_size = 2*size;
            T* n_tab = new T[n_size];
        
            // przeniesienie danych do nowej tablicy
            for (int i=0; i<size; i++) {
                n_tab[i]=tab[i];
            }
            delete[] tab;
            tab = n_tab;
            size = n_size;
            return size;
        }
        
        void add_end(T element) {
            if(actual==size){resize();}
            tab[actual]=element;
            actual++;
        }
        
        void del_end(){
            delete tab[actual-1];
            if (actual > 0) {
                actual--;
            }    
        }
        
        void display(){
        for(int i = 0; i<actual; i++) {
            cout<<"("<<tab[i]->data<<","<<tab[i]->priority<<")"<<endl;
        }
        }
};
#endif
