#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

int main()
{
    std::fstream file("kursy_usd_eur.csv", std::fstream::in);
    std::vector<Exchange_rate> rates;
    if (file.is_open()) {
        std::string line;
        int next, pos;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            Exchange_rate er;
            next = line.find(',');
            er.date = line.substr(0, next);
            pos = next + 1;

            // usd
            next = line.find(',', pos);
            er.usd = std::stod(line.substr(pos, next - pos));
            pos = next + 1;

            // eur
            next = line.find(',', pos);
            er.eur = std::stod(line.substr(pos, next - pos));
            pos = next + 1;

            // table_id
            er.table_id = line.substr(pos);
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }
    else
        cout<<"nie mozna otworzyc pliku";

    cout<<rates[0].date<<","<<rates[0].eur<<","<<rates[0].usd<<","<<rates[0].table_id<<endl;
    return 0;
}
