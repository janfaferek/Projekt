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

int binary_search(const vector<Exchange_rate> &rates, double szukana = 3.9011)
{
    int left = 0;
    int right = rates.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (rates[mid].usd == szukana)
            return mid;

        if (rates[mid].usd < szukana)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // nie znaleziono
}

int main()
{
    fstream file("kursy_usd_eur.csv", fstream::in);

    vector<Exchange_rate> rates;

    if (!file.is_open()) {
        cout << "Nie mogę otworzyć pliku!" << endl;
        return 1;
    }
    if (file.is_open()) {
        string line;
        getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            string double_str;
            getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = stod(double_str);      //zamiana na string->double
            getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = stod(double_str);      //zamiana na string->double
            getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }
    sort_usd(rates);
    for(int i = 0; i<10; i++)
        cout<<rates[rates.size()-1-i].date<<" "<<rates[rates.size()-1-i].usd<<endl;
    cout<<endl<<endl;
    int indeks = binary_search(rates);
    cout<<"kurs byl w dniu: "<<rates[indeks].date;
    cout<<endl<<endl;
    sort_eur(rates);
    for(int i = 0; i<10; i++)
        cout<<rates[rates.size()-1-i].date<<" "<<rates[rates.size()-1-i].eur<<endl;

    return 0;
}
