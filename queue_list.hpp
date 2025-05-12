#ifndef queue_list_hpp
#define queue_list_hpp

#include <iostream>
using namespace std;

template <typename T>
struct Element {
    T value;
    T priority;
    Element<T>* next;

    Element(T e, T p) : value(e), priority(p), next(nullptr) {}
};

template <typename T>
class Queue_List {
    Element<T>* head;
    public:
        Queue_List() {head=nullptr; size = 0;}

        ~Queue_List(){
            Element<T>* current = head;
            while (current != nullptr) {
                Element<T>* temp = current;
                current = current->next;
                delete temp;
            }
        }

        void insert(T e, T p) {
            Element<T>* node = new Element<T>(e,p);
            if(head == nullptr || head->priority < p) {
                node -> next = head;
                head = node;
            }else {
                Element<T>* current = head;
                while (current->next != nullptr && current->next->priority >= p) {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
            }
            size++;
        }

        T extract_max(){
            if (head == nullptr) {
                cout << "kolejka jest pusta" << endl;
                return -1;
            }
            T max = head -> value;
            Element<T>* temp = head -> next;
            delete head;
            head = temp;
            size--;
            return max;
        }

        T find_max() const{
            if (head == nullptr) {
                cout << "kolejka jest pusta" << endl;
                return;
            }
            T max = head -> value;
            return max;
        }

        void modify_key(T e, T p) {
            Element<T>* temp = head;
            Element<T>* prev = nullptr;
            bool found = false;
            
            while(temp!=nullptr) {
                if(temp->value == e){
                    // usuniecie istniejacego elementu
                    if(prev==nullptr) {
                        head = temp->next;
                    }else{
                        prev -> next = temp-> next;
                    }
                    delete temp;
                    found = true;
                    size--; // zmniejszenie rozmiaru poniewaz fukcja insert go zwieksza
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if(found) {
                insert(e,p);
            } else {
                cout << "element o wartosci " << e << " nie zostal odnaleziony" << endl;
            }
        }

        int return_size() const{
            return size;
        }

        void print() const{
            Element<T>* current = head;
            cout << "(value:priority): ";
            while (current != nullptr) {
                cout << current->value << ":" << current->priority << " ";
                current = current->next;
            }
            cout << endl;
        }
    private:
        int size;
};
#endif