#include <iostream>
#include <random>
#include <limits>
#include <fstream>

void zapisz_losowe_dane_do_pliku(int ilosc,int ktory) {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dist(0, std::numeric_limits<int>::max());
    std::uniform_int_distribution<int> dist_p(0, ilosc*5);
    std::string nazwa_pliku = "dane_" + std::to_string(ilosc)+"_"+std::to_string(ktory) + ".txt";
    std::ofstream plik(nazwa_pliku);

    if (!plik.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu!" << std::endl;
        return;
    }

    for (int i = 0; i < ilosc; ++i) {
        int liczba = dist(gen);
        int priorytet = dist_p(gen);
        plik << liczba <<" "<< priorytet<< "\n";
    }

    plik.close();
    std::cout << "Zapisano " << ilosc << " liczb do pliku: " << nazwa_pliku << std::endl;
}

int main(){
    for(int i=0;i<10;i++){
    zapisz_losowe_dane_do_pliku(5000,i);
    zapisz_losowe_dane_do_pliku(8000,i);
    zapisz_losowe_dane_do_pliku(10000,i);
    zapisz_losowe_dane_do_pliku(16000,i);
    zapisz_losowe_dane_do_pliku(20000,i);
    zapisz_losowe_dane_do_pliku(40000,i);
    zapisz_losowe_dane_do_pliku(60000,i);
    zapisz_losowe_dane_do_pliku(80000,i);
    zapisz_losowe_dane_do_pliku(100000,i);
    }

}