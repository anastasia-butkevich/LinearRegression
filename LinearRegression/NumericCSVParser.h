#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class NumericCSVParser
{
public:
    string fileName;
    vector<vector<double>> data;
    vector<string> headers;
    bool hasHeader;
    char delimiter;
    ifstream fileStream;

    NumericCSVParser(string& _filename, bool _header = true, char _del = ',');
    bool loadData();
    vector<string> parseRow(string &row);
    vector<vector<double>> getData();
    pair <vector<double>, vector<vector<double>>> inputOutputSplit(string outputHeader);
    ~NumericCSVParser();
};