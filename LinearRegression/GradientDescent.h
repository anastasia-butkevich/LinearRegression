#pragma once
#include <vector>
using namespace std;

class GradientDescent
{
public:
    static void optimize(vector<vector<double>> X, vector<double> y, 
        vector<double> &W, double &b, vector<double> &costs, double alpha, int epochs, double lambda);
};