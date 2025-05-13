#include <iostream>
#include "queue_list.hpp"
#include <fstream>
#include <vector>
#include <chrono>
#include <numeric>
#include "Heap.hpp"
#include <random>
#include <limits>

void testy(int decyzja_){
    Heap<int> heap(1);
    Queue_List<int> queue;
    int index;
    int decyzja;
    std::string buff;
    bool temp=true;
    int liczba;
    int priorytet;
    while(temp){
    system("clear");    
    std::cout<<"TESTOWANIE STRUKTURY:"<<std::endl<<"Wybierz opcje testu:"<<std::endl;
    std::cout<<"1. Test funkcji insert"<<std::endl<<
               "2. Test funkcji extract_max"<<std::endl<<
               "3. Test funkcji peek_max"<<std::endl<<
               "4. Test funkcji modify_key"<<std::endl<<
               "5. Test funkcji return_size"<<std::endl<<
               "6. Wroc"<<std::endl;

    
    std::cin>>decyzja;
    switch (decyzja)
    {
    case 1:{
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj priorytet"<<std::endl;
            cin>>priorytet;
            heap.insert(liczba,priorytet);
        }
        else if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj priorytet"<<std::endl;
            cin>>priorytet;
            queue.insert(liczba,priorytet);
        }
    }
        break;
    case 2:{
        system("clear"); 
        if(decyzja_==1){
            system("clear");
            cout<<heap.extract_max()<<endl;
        }
        else if(decyzja_==2){
            system("clear");
            cout<<queue.extract_max()<<endl;
        }
    }
        break;
    case 3:{
        if(decyzja_==1){
            system("clear");
            cout<<heap.peak_max()<<endl;
            
        }
        else if(decyzja_==2){
            system("clear");
            cout<<queue.find_max();
        }
    }
        break;
    case 4:
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj priorytet"<<std::endl;
            cin>>priorytet;
            heap.modify_key(liczba,priorytet);
        }
        else if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj priorytet"<<std::endl;
            cin>>priorytet;
            queue.modify_key(liczba,priorytet);
        }
        break;
    case 5:
        if(decyzja_==1){
            system("clear");
            cout<<heap.return_size();
        }
        else if(decyzja_==2){
            system("clear");
            cout<<queue.return_size();
        }
        break;
    
    case 6:
        temp=false;
        break;
    default:
        temp=false;
        break;
    }
    std::cout<<std::endl;
    if(decyzja_==1){
        heap.display();
    }
    else if(decyzja_==2){
        queue.print();
    }
    
    std::cout<<std::endl<<"wpisz co kolwiek"<<std::endl;
    std::cin>>buff;
    }

    
}



void wybor_struktury(){
    system("clear"); 
    int decyzja;
    std::cout<<"TESTOWANIE STRUKTUR:"<<std::endl<<"Wybierz struktury do testu:"<<std::endl;
    std::cout<<"1. Kopiec"<<std::endl<<
               "2. Lista"<<std::endl<<endl;
    std::cin>>decyzja;
    testy(decyzja);

}


int main(){
    while (true)
    {
    wybor_struktury();
    }
    return 0;
}