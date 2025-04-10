#pragma once
#include <vector>
using namespace std;

class CostFunction
{
public:
    static double MSE(vector<double> yPred, vector<double> yTrue);
};