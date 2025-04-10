#include "GradientDescent.h"
#include "CostFunction.h"

void GradientDescent::optimize(vector<vector<double>> X, vector<double> y, 
    vector<double> &W, double &b, vector<double> &costs, double alpha, int epochs, double lambda)
{
    int m = X.size();
    int n = X[0].size();

    for (int epoch = 0; epoch < epochs; epoch++)
    {
        double updateBias = 0.0;
        vector<double> updateWeights(n, 0.0);
        vector<double> yPred(m, 0.0);

        for (size_t i = 0; i < m; i++)
        {
            double error = 0.0;
            double prediction = b;
            for (int j = 0; j < n; j++)
            {
                prediction += W[j] * X[i][j];
            }
            error = prediction - y[i];
            yPred[i] = prediction;

            for (size_t j = 0; j < n; j++)
            {
                updateWeights[j] += (1.0 / m) * X[i][j] * error;
            }
            updateBias += (1.0 / m) * error;
        }

        for (size_t j = 0; j < n; j++)
        {
            W[j] -= alpha * (updateWeights[j] + lambda * W[j]);
        }
        b -= alpha * updateBias;

        double sumOfSquares = 0.0;
        for (int j = 0; j < W.size(); j++) {
            sumOfSquares += W[j] * W[j];
        }
        double regularizationTerm = (lambda / (2 * m)) * sumOfSquares;
        costs[epoch] = CostFunction::MSE(yPred, y) + regularizationTerm;
    }
}
