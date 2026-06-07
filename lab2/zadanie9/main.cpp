#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct stacja
{
    string date;
    string czas;
    double v_dzwiek;
    double temp_dzwiek;
    double cisnienie_atmo;
    double temp;
    double wilgotnosc;
    double kompas;
    double predkosc_uv;
    double predkosc_wiatr;
    double kierunek;
    double wysokosc;
    double temp_pomieszczenia;
};

double max_temp (vector<stacja> &vec)
{
    double max =vec[0].temp;
    for(int i = 0; i<vec.size(); i++)
    {
        if (vec[i].temp > max)
            max = vec[i].temp;
    }
    return max;
}

double min_temp (vector<stacja> &vec)
{
    double min = vec[0].temp;
    for(int i = 0; i<vec.size(); i++)
    {
        if (vec[i].temp < min)
            min = vec[i].temp;
    }
    return min;
}

double mediana(vector<stacja> rates)
{
    stacja temp;
    int rozmiar = rates.size();
    while (rozmiar > 0)
    {
        for(int i =0 ; i<rozmiar - 1; i++)
        {
            if(rates[i].temp > rates[i+1].temp)
            {
                temp = rates[i];
                rates[i] = rates[i+1];
                rates[i+1] = temp;
            }
        }
        rozmiar--;
    }
    int n = rates.size();
    if (n % 2 == 1)
        return rates[n/2].temp;

    return (rates[n/2 - 1].temp + rates[n/2].temp) / 2.0;

}



int main()
{
    fstream file("temp02-2020.csv", fstream::in);

    vector<stacja> rates;

    if (!file.is_open()) {
        cout << "Nie mogę otworzyć pliku!" << endl;
        return 1;
    }
    if (file.is_open()) {
        string line;
        getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            stacja er;
            getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            getline(str, er.czas, ','); //wczytuje czas
            string double_str;

            getline(str, double_str, ',');
            er.v_dzwiek = stod(double_str);

            getline(str, double_str, ',');
            er.temp_dzwiek = stod(double_str);

            getline(str, double_str, ',');
            er.cisnienie_atmo = stod(double_str);

            getline(str, double_str, ',');
            er.temp = stod(double_str);

            getline(str, double_str, ',');
            er.wilgotnosc = stod(double_str);

            getline(str, double_str, ',');
            er.kompas = stod(double_str);

            getline(str, double_str, ',');
            er.predkosc_uv = stod(double_str);

            getline(str, double_str, ',');
            er.predkosc_wiatr = stod(double_str);

            getline(str, double_str, ',');
            er.kierunek = stod(double_str);

            getline(str, double_str, ',');
            er.wysokosc = stod(double_str);

            getline(str, double_str, ',');
            er.temp_pomieszczenia = stod(double_str);

            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }
    double min = min_temp(rates);
    cout<<"najmniejsza temp: "<<min<<endl;

    double max = max_temp(rates);
    cout<<"najwieksza temp: "<<max<<endl;

    double median = mediana(rates);
    cout<<"mediana: "<<median; //??????

    return 0;
}
