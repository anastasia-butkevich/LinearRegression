#include "LinearRegressor.h"
#include "GradientDescent.h"

LinearRegressor::LinearRegressor(vector<vector<double>> _Xtrain, vector<vector<double>> _Xtest, 
                                        vector<double> _yTrain, vector<double> _yTest, double _alpha, int _epochs)
    : Xtrain(_Xtrain)
    , Xtest(_Xtest)
    , yTrain(_yTrain)
    , yTest(_yTest)
    , alpha(_alpha)
    , epochs(_epochs)
{
}

void LinearRegressor::fit(vector<vector<double>> Xtrain, vector<double> yTrain, double alpha, int epochs)
{
    tuple<vector<double>, double, vector<double>> WeightsBiasCosts = GradientDescent::optimize(Xtrain, yTrain, alpha, epochs);

    W = get<0>(WeightsBiasCosts);
    b = get<1>(WeightsBiasCosts);
    costs = get<2>(WeightsBiasCosts);
}

vector<double> LinearRegressor::predict(vector<vector<double>> Xtest) const
{
    int m = Xtest.size();
    int n = Xtest[0].size();

    vector<double> yPred(m, 0.0);
    for (int i = 0; i < m; i++)
    {
        double prediction = b;
        for (int j = 0; j < n; j++)
        {
            prediction += W[j] * Xtest[i][j];
        }
        yPred[i] = prediction;
    }
    return yPred;
}

LinearRegressor::~LinearRegressor()
{
}
