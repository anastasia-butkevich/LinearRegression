#include "CostFunction.h"

double CostFunction::MSE(vector<double> yPred, vector<double> yTrue)
{
    double cost = 0.0;
    int m = yTrue.size();

    for (size_t i = 0; i < yTrue.size(); i++)
    {
        double diff = yPred[i] - yTrue[i];
        cost += diff * diff;
    }

    cost /= (2.0 * m);
    return cost;
}
