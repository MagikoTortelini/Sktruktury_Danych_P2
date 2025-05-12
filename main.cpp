#include <iostream>
#include "Heap.hpp"
#include <fstream>
#include <vector>
#include <chrono>
#include <numeric>
#include "queue_list.hpp"
#include <random>
#include <limits>

using namespace std::chrono;
using namespace std;
void Test_insert(int ilosc,int typ,int liczba_,int priorytet){

    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Heap<int> heap(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    heap.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                heap.insert(liczba_,priorytet);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Queue_List<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    list.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                list.insert(liczba_,priorytet);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}

void Test_extract(int ilosc,int typ){

    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Heap<int> heap(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    heap.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                heap.extract_max();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Queue_List<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    list.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                list.extract_max();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}

void Test_peek(int ilosc,int typ){

    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Heap<int> heap(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    heap.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                heap.peak_max();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Queue_List<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    list.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                list.find_max();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void Test_Modify(int ilosc,int typ,int priorytet){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dist(0,ilosc-1);
    int pozycja=dist(gen);
    int liczba;
    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Heap<int> heap(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    if(i==pozycja){
                        liczba=e;
                    }
                    
                    heap.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                heap.modify_key(liczba,priorytet);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Queue_List<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    if(i==pozycja){
                        liczba=e;
                    }
                    list.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                list.modify_key(liczba,priorytet);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void Test_size(int ilosc,int typ){

    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Heap<int> heap(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    heap.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                heap.return_size();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Queue_List<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                for(int i=0;i<ilosc;i++){
                    int e;
                    int p;
                    plik>>e>>p;
                    
                    list.insert(e,p);
                    
                }
                auto start=high_resolution_clock::now();
                list.return_size();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}

void testy(int decyzja_){
    std::vector<int> zakres={5000,8000,10000,16000,20000,40000,60000,80000,100000};
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    
    int decyzja;
    std::string buff;
    bool temp=true;
    int liczba;
    int priorytet;
    while(temp){
    system("clear");    
    std::cout<<"TESTOWANIE STRUKTURY:"<<std::endl<<"Wybierz opcje testu:"<<std::endl;
    std::cout<<"1. Test Insert"<<std::endl<<
               "2. Test Extract_max"<<std::endl<<
               "3. Test Peek_max"<<std::endl<<
               "4. Test Modify_key"<<std::endl<<
               "5. Test Return_size"<<std::endl<<
               "6. Test Wroc"<<std::endl;

    
    std::cin>>decyzja;
    switch (decyzja)
    {
    case 1:{
        system("clear"); 
        
        for(int i=0;i<zakres.size();i++){
            std::uniform_int_distribution<int> dist(0,std::numeric_limits<int>::max());
            std::uniform_int_distribution<int> dist_p(0,zakres[i]*5); 
            liczba=dist(gen);
            priorytet=dist_p(gen);
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            Test_insert(zakres[i],decyzja_,liczba,priorytet);
        }
    }
        break;
    case 2:{
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            Test_extract(zakres[i],decyzja_);
        }
    }
        break;
    
    case 3:{
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            Test_peek(zakres[i],decyzja_);
        }
    }
        break;
    case 4:{
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::uniform_int_distribution<int> dist(0,std::numeric_limits<int>::max());
            std::uniform_int_distribution<int> dist_p(0,zakres[i]*5); 
            liczba=dist(gen);
            priorytet=dist_p(gen);
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            Test_Modify(zakres[i],decyzja_,priorytet);
        }
    }
        break;
    
    case 5:{
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            Test_size(zakres[i],decyzja_);
        }
    }
        break;
    
    case 6:
        temp=false;
        break;
    default:
        temp=false;
        break;
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
               "2. Lista"<<std::endl;
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