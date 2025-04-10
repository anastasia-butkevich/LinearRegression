#include "LinearRegressor.h"
#include "GradientDescent.h"

LinearRegressor::LinearRegressor(vector<vector<double>> _Xtrain, vector<vector<double>> _Xtest,
                    vector<double> _yTrain, vector<double> _yTest, double _alpha, int _epochs, double _lambda)
    : Xtrain(_Xtrain)
    , Xtest(_Xtest)
    , yTrain(_yTrain)
    , yTest(_yTest)
    , alpha(_alpha)
    , epochs(_epochs)
    , lambda(_lambda)
{
    W = vector<double>(_Xtrain[0].size(), 0.0);
    b = 0.0;
    costs = vector<double>(_epochs, 0.0);
}

void LinearRegressor::fit()
{
    GradientDescent::optimize(Xtrain, yTrain, W, b, costs, alpha, epochs, lambda);
}

vector<double> LinearRegressor::predict(vector<vector<double>> Xtest) const
{
    int m = Xtest.size();
    int n = Xtest[0].size();

    vector<double> yPred(m, 0.0);
    for (size_t i = 0; i < m; i++)
    {
        double prediction = b;
        for (size_t j = 0; j < n; j++)
        {
            prediction += W[j] * Xtest[i][j];
        }
        yPred[i] = prediction;
    }
    return yPred;
}

vector<double> LinearRegressor::getCosts() const
{
    return costs;
}

LinearRegressor::~LinearRegressor()
{
}
