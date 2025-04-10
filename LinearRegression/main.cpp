#include "LinearRegressor.h"
#include "CostFunction.h"
#include "NumericCSVParser.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<double> y;
    vector<vector<double>> X;
    vector<double> costs;
    vector<double> yPred;
    double mse;
    int epochs = 1000;
    double alpha = 0.01;
    double lambda = 0.1;
    string filename = "data_cleaned.csv";  // Assuming data are normalized
    string target = "price";
    NumericCSVParser parser(filename);
    bool opened = parser.loadData();
    if (!opened)
    {
        return 1;
    }
    
    pair <vector<double>, vector<vector<double>>> splitData = parser.inputOutputSplit(target);
    y = splitData.first;
    X = splitData.second;

    int totalSize = y.size();
    int trainSize = static_cast<int>(totalSize * 0.8); 

    vector<double> yTrain(y.begin(), y.begin() + trainSize);
    vector<vector<double>> Xtrain(X.begin(), X.begin() + trainSize);

    vector<double> yTest(y.begin() + trainSize, y.end());
    vector<vector<double>> Xtest(X.begin() + trainSize, X.end());

    LinearRegressor model(Xtrain, Xtest, yTrain, yTest, alpha, epochs, lambda);
    model.fit();
    costs = model.getCosts();

    for (int i = 0; i < epochs; i++) {
        if (i % 100 == 0) {
            cout << "Cost at epoch " << i << ": " << costs[i] << endl;
        }
    }
    cout << "Final cost: " << costs.back() << endl;

    yPred = model.predict(Xtest);

    mse = CostFunction::MSE(yTest, yPred);
    cout << "Mean Squared Error on test set: " << mse << endl;

    return 0;
}
