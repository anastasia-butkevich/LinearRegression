#include "NumericCSVParser.h"

NumericCSVParser::NumericCSVParser(string& _filename, bool _header, char _del)
    : fileName(_filename)
    , hasHeader(_header)
    , delimiter(_del)
{
}

bool NumericCSVParser::loadData()
{
    fileStream.open(fileName);
    if (!fileStream.is_open())
    {
        cout << "Error opening the file: " << fileName << endl;
        return false;
    }

    string line;
    if (hasHeader && getline(fileStream, line))
    {   
        headers = parseRow(line);
    }

    while (getline(fileStream, line))
    {
        vector<string> strRow;
        vector<double> doubleRow;

        strRow = parseRow(line);
        for (string &value : strRow)
        {
            doubleRow.push_back(stod(value));
        }
        data.push_back(doubleRow);
    }
    fileStream.close();
    return true;
}

vector<string> NumericCSVParser::parseRow(string &row)
{
    vector<string> rowData;
    istringstream ss(row);
    string value;

    while (getline(ss, value, delimiter))
    {
        rowData.push_back(value);
    }
    return rowData;
}

vector<vector<double>> NumericCSVParser::getData()
{
    return data;
}

pair<vector<double>, vector<vector<double>>> NumericCSVParser::inputOutputSplit(string outputHeader)
{
    vector<double> output;
    vector<vector<double>>  input;
    int outputIndex = -1;
    for (size_t i = 0; i < headers.size(); i++)
    {
        if (headers[i] == outputHeader)
        {
            outputIndex = i;
            break;
        }
    }

    if (outputIndex != -1)
    {
        for (vector<double> &row : data)
        {
            vector<double> newRow;
            output.push_back(row[outputIndex]);

            for (size_t i = 0; i < row.size(); ++i) {
                if (i != outputIndex) {
                    newRow.push_back(row[i]);
                }
            }
            input.push_back(newRow);
        }
    } 
    else
    {
        cerr << "Error: Output header \"" << outputHeader << "\" not found.\n";
    }
    return make_pair(output, input);
}

NumericCSVParser::~NumericCSVParser()
{
}
