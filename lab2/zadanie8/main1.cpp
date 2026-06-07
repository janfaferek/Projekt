#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Exchange_rate
{
    string date;
    double usd;
    double eur;
    string table_id;
};

vector<Exchange_rate> sort_usd(vector<Exchange_rate> &rates)
{
    Exchange_rate temp;
    int rozmiar = rates.size();
    while (rozmiar > 0)
    {
        for(int i =0 ; i<rozmiar - 1; i++)
        {
            if(rates[i].usd > rates[i+1].usd)
            {
                temp = rates[i];
                rates[i] = rates[i+1];
                rates[i+1] = temp;
            }
        }
        rozmiar--;
    }
    return rates;
}

vector<Exchange_rate> sort_eur(vector<Exchange_rate> &rates)
{
    Exchange_rate temp;
    int rozmiar = rates.size();
    while (rozmiar > 0)
    {
        for(int i =0 ; i<rozmiar - 1; i++)
        {
            if(rates[i].eur > rates[i+1].eur)
            {
                temp = rates[i];
                rates[i] = rates[i+1];
                rates[i+1] = temp;
            }
        }
        rozmiar--;
    }
    return rates;
}

int main()
{
    fstream file("kursy_usd_eur.csv", fstream::in);
    vector<Exchange_rate> rates;
    if (file.is_open()) {
        string line;
        getline(file, line); // wczytuje pierwsz¹ liniê z nag³ówkiem i j¹ ignoruje
        while (getline(file, line)) {//wczytuje kolejne linie a¿ do koñca pliku
            stringstream str(line);//tworzy strumieñ, którego Ÿród³em jest wczytana linia

            Exchange_rate er;
            getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            string double_str;
            getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = stod(double_str);      //zamiana na string->double
            getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = stod(double_str);      //zamiana na string->double
            getline(str, er.table_id, ','); // wczytuje ostatni¹ kolumnê z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }
    sort_usd(rates);
    for(int i = 0; i<10; i++)
        cout<<rates[rates.size()-1-i].date<<" "<<rates[rates.size()-1-i].usd<<endl;
    cout<<endl<<endl;
    sort_eur(rates);
    for(int i = 0; i<10; i++)
        cout<<rates[rates.size()-1-i].date<<" "<<rates[rates.size()-1-i].eur<<endl;

    return 0;
}
