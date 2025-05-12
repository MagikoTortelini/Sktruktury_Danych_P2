#ifndef heap_hpp
#define heap_hpp
#include "tablica_dynamiczna.hpp"
template <typename T>
struct NodeS // Struktura bloku przechowujca dane i priorytet
{
    T data;
    T priority;

    NodeS(T _data,T _priority){
        data=_data;
        priority=_priority;
    }
};


template <typename T>
class Heap{
    private:
        Tablica_dynamiczna<NodeS<T>*> tablica; // wskaznik na tablice przechowujacej bloki
    public: 
        // konstruktor i desktruktor
        Heap(int size):tablica(size){};
        
        ~Heap()=default;
        int return_size(){
            return tablica.get_size();
        }


        void insert(T e,T p){
            NodeS<T>* Node= new NodeS<T>(e,p);
            tablica.add_end(Node); // dodanie elementu na koncu tablicy
            heapup(tablica.get_size()-1); // naprawa kopca w gore
        }
        void display(){
            tablica.display(); // wyswietlenie kopca
        }
        void heapdown(int parent,int s){
            auto childl = (parent* 2) + 1; // znaleznienie lewego dziecka
            if(childl>=s){ // jezeli dziecko jest poza zakresem tablicy przerywamy funkcje
                return;
            }
            auto childr=childl+1; // znalezienie prawego dziecka
            if(childr<s&&tablica.get(childr)->priority>tablica.get(childl)->priority){ // jezlie prawe dziecko znajduje sie w zakresie tablicy oraz jest wieksze od lewego dziecka przechodzimy dalej
                if(tablica.get(childr)->priority>tablica.get(parent)->priority){ // sprawdzamy czy prawgo dziecko jest wieksze od rodzica
                swap(tablica.get(parent),tablica.get(childr)); // zamieniamy miejscami prawe dziecko i rodzica
                heapdown(childr,s); // wywolujemy ponownie funkcje dla zamienionego prawego dziecka
                }
            }
            else if((childr)<s&&tablica.get(childr)->priority<tablica.get(childl)->priority){ // jezlie prawe dziecko znajduje sie w zakresie tablicy oraz jest mniejsze od lewego dziecka przechodzimy dalej
                if(tablica.get(childl)->priority>tablica.get(parent)->priority){ // sprawdzamy czy lewe dziecko jest wieksze od rodzica
                    swap(tablica.get(parent),tablica.get(childl)); // zamieniamy miejscami lewe dziecko i rodzica
                    heapdown(childl,s); // wywolujemy ponownie funkcje dla zamienionego lewego dziecka
                    }
            }
        }
        void heapup(int index){
            while(index>0&&tablica.get((index-1)/2)->priority<tablica.get(index)->priority) // dopoki index nie jest 0 i priorytet rodzica nie jest wiekszy
            {
                swap(tablica.get(index),tablica.get((index-1)/2)); // zamieniamy dziecko z rodzicem
                index=(index-1)/2; // zamieniamy index

            }
        }
        NodeS<T>* peak_max(){
            return tablica.get(0);
        }
        NodeS<T>* extract_max()
        {
            if(tablica.get_size()==0){
                return nullptr;
            }
            NodeS<T>* Max_Priority = tablica.get(0); // przechowanie elemenetu o najwyzszym priorytecie
            swap(tablica.get(0),tablica.get(tablica.get_size()-1)); // zamiana miejscami pierwszego i ostatniego elementu
            tablica.del_end(); // usuniecie elementu o najwyzszym priorytecie
            heapdown(0,tablica.get_size()); // naprawa kopca w dol
            return Max_Priority; // zwrocenie elementu o najwyzszym priorytecie
        }
        void modify_key(T e, T p)
        {
            int index=-1; 
            int s=tablica.get_size();

            for(int i=0;i<s-1;i++) // szukanie w tablicy szukanego elementu
            {
                if(tablica.get(i)->data==e){
                    index=i;
                    break;
                }
            }
            if(index==-1){ // w przypadku nie znaleznienie elementu poinformowanie uzytkownika
                cout<<"Brak takiego elementu"<<endl;
                return;
            }

            if(tablica.get(index)->priority>p) // sprawdznie czy nowy priorytet jest wiekszy czy mniejszy od starego
            {
                tablica.get(index)->priority=p; // jezel jest mniejszy naprawa kopca w dol
                heapdown(index,s);
            }
            else{
                tablica.get(index)->priority=p; // jezeli jest wiekszy naprawa kopca w gore
                heapup(index);
            }
        }

};
#endif
