#include <iostream>
#include "std_lib_facilities.h"

double mean (vector<double> series);
double median(vector<double> series);


int main() //Computes mean and median of a series of temperatures
{
    vector<double> temps;
    for (double temp; cin>>temp;)
        temps.push_back(temp);

    cout << "Average temperature: " << mean(temps) << '\n';
    cout << "Median temperature: " << median(temps) << '\n';
}


/* -------------------------- Functions used -------------------------- */
double mean (vector<double> series)
{
    double sum = 0, average = 0;
    for (double x : series) sum += x;
    average = sum / series.size();

    return average;
}

double median(vector<double> series)
{
    sort(series);
    double median = 0;

    //If number of values in the series is odd:
    if (series.size() % 2 != 0)
    {
        double rank = 0;
        rank = (series.size()+1)/2;
        median = series[rank-1];

    }

    //If number of values in the series is even:
    else
    {
        double rank1 = 0, rank2 = 0;
        rank1 = series.size()/2;
        rank2 = series.size()/2 + 1;
        median = (series[rank1-1] + series[rank2-1])/2;
    }

    return median;
}