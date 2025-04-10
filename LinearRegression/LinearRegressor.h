#pragma once
#include <vector>
using namespace std;

class LinearRegressor
{
private:
    vector<vector<double>> Xtrain, Xtest;
    vector<double> yTrain, yTest;
    vector<double> W;
    double b;
    vector<double> costs;
    double alpha;
    int epochs;
    double lambda;
public:
    LinearRegressor(vector<vector<double>> _Xtrain, vector<vector<double>> _Xtest,
        vector<double> _yTrain, vector<double> _yTest, double _alpha, int _epochs, double _lambda);
    void fit();
    vector<double> predict(vector<vector<double>> Xtest) const;
    vector<double> getCosts() const;
    ~LinearRegressor();
};