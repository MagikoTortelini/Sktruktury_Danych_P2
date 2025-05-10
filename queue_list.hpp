#ifndef queue_list_hpp
#define queue_list_hpp

#include <iostream>
using namespace std;

struct Element {
    int value;
    int priority;
    Element* next;

    Element(int e, int p) {
        value = e;
        priority = p;
        next=nullptr;
    }
};

class Queue_List {
    Element* head;
    public:
        Queue_List() {head=nullptr; size = 0;}

        ~Queue_List(){
            Element* current = head;
            while (current != nullptr) {
                Element* temp = current;
                current = current->next;
                delete temp;
            }
        }

        void insert(int e, int p) {
            Element* node = new Element(e,p);
            if(head == nullptr || head->priority < p) {
                node -> next = head;
                head = node;
            }else {
                Element* current = head;
                while (current->next != nullptr && current->next->priority >= p) {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
            }
            size++;
        }

        int extract_max(){
            int max = head -> value;
            Element* temp = head -> next;
            delete head;
            head = temp;
            size--;
            return max;
        }

        int find_max() const{
            int max = head -> value;
            return max;
        }

        void modify_key(int e, int p) {
            Element* temp = head;
            Element* prev = nullptr;
            
            while(temp!=nullptr) {
                if(temp->value == e){
                    if(prev==nullptr) {
                        head = temp->next;
                    }else{
                        prev -> next = temp-> next;
                    }
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            insert(e,p);
        }

        int return_size() {
            return size;
        }
    private:
        int size;
};
#endif