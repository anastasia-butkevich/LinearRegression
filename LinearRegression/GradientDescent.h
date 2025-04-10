#pragma once
#include <vector>
#include <tuple>
using namespace std;

class GradientDescent
{
public:
    static tuple<vector<double>, double, vector<double>> optimize(vector<vector<double>> X, vector<double> y, double alpha, int epochs);
};