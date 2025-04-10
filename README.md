# Linear Regression Model C++
This project implements a linear regression model with regularization using gradient descent in C++. The model predicts continuous values (such as housing prices) based on input features and can be trained using a dataset. House pricing dataset used for demonstration. 
## Overview
This project provides a C++ implementation of a linear regression model that uses gradient descent to minimize the cost function, with the addition of regularization (Ridge Regression). The code includes the following key components:

- Custom CSV parser for numeric data: Parses numeric data from CSV files with support for headers and custom delimiters.
- Gradient Descent Algorithm: Optimizes the weights and bias of the linear regression model.
- Cost Function (MSE): Calculates the Mean Squared Error (MSE) for evaluating the model performance.
- Regularization: Uses L2 regularization (Ridge) to avoid overfitting.
- Model Evaluation: The model is evaluated using MSE on a test set after training.

The project loads a dataset from a CSV file, splits it into training and test sets, trains the model, and outputs the cost and MSE during the training process.

## Usage
### 1. Input data
Ensure your dataset (CSV) is available and formatted correctly. It should contain only continuous normalized values. The dataset should have columns representing input features and a target variable (e.g., price, like in this example). Change the target variable accordingly to your dataset.
### 2. Run the Model
Open the main.cpp file and adjust the following parameters as needed:  
`filename`: Path to the dataset (e.g., "data_cleaned.csv").  
`target`: The name of a target variable.  
`alpha`: Learning rate for gradient descent.  
`epochs`: Number of iterations for training.  
`lambda`: Regularization parameter.  
And build and run the project (in IDE or command line).
### 3. Output
The program will output the cost at each epoch and the final MSE on the test set. The costs array will contain the value of the cost function after each epoch.  

**Example Output (housing price dataset):**
```
Cost at epoch 0: 0.210347
Cost at epoch 100: 0.0924524
Cost at epoch 200: 0.0865652
...
Final cost: 0.0830284
Mean Squared Error on test set: 1.62752
```
