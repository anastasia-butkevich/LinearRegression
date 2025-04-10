#include "GradientDescent.h"
#include "CostFunction.h"

tuple<vector<double>, double, vector<double>> GradientDescent::optimize(vector<vector<double>> X, vector<double> y, double alpha, int epochs)
{
    int m = X.size();
    int n = X[0].size();
    double b = 0.0;
    vector<double> W(n, 0.0);
    vector<double> costs;

    for (int epoch = 0; epoch < epochs; epoch++)
    {
        double updateBias = 0.0;
        vector<double> updateWeights(n, 0.0);
        vector<double> yPred(m, 0.0);

        for (int i = 0; i < m; i++)
        {
            double error = 0.0;
            double prediction = b;
            for (int j = 0; j < n; j++)
            {
                prediction += W[j] * X[i][j];
            }
            error = prediction - y[i];
            yPred[i] = prediction;

            for (int j = 0; j < n; j++)
            {
                updateWeights[j] += (1.0 / m) * X[i][j] * error;
            }
            updateBias += (1.0 / m) * error;
        }

        for (int j = 0; j < n; j++)
        {
            W[j] -= alpha * updateWeights[j];
        }
        b -= alpha * updateBias;

        costs[epoch] = CostFunction::MSE(yPred, y);
    }

    return make_tuple(W, b, costs);
}
