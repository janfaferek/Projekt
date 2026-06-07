#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void min_max(vector<double> &param, double min, double max)
{
     min =  *min_element(param.begin(), param.end()); //min_element zwraca iterator (taki jakby wskaźnik)
     max = *max_element(param.begin(), param.end());  // to samo
     cout<<"Min: "<<min<<" ,"<<" max: "<<max;
}

int main()
{
    double min;
    double max;
    vector<double> values = {-1.0, 100, 3.14, -999.9, 21.37};
    min_max(values, min, max);


}
