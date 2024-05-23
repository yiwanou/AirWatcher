// g++ - Wall - std = c++ 11 - o test test.cpp &&./ test
#include <string>
#include <fstream>
#include <vector>
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream
#include <iostream>


using namespace std;

class CSVload
{
private:
public:
    CSVload();
    ~CSVload();

    vector<vector<string>> readCSV(string filename);
};



CSVload::CSVload()
{
}

CSVload::~CSVload()
{
}

vector<vector<string>> CSVload::readCSV(string filename)
{
    // Create an input filestream
    ifstream file(filename);

    // Make sure the file is open
    if (!file.is_open())
        throw runtime_error("Could not open file");

    string line;

    vector<vector<string>> all_lines;

    if (file.good())
    {

        // Extract all the lines in the file
        while (getline(file, line))
        {
            line.erase(line.find_last_not_of(" \n\r\t") + 1);

            // Create a stringstream from line
            stringstream ss(line);

            // Extract each case
            string cell;
            vector<string> cells_line;
            while (getline(ss, cell, ','))
            {
                cells_line.push_back(cell);
            }
            all_lines.push_back(cells_line);
        }
        return all_lines;
    }
    else
    {
        throw runtime_error("Could not read file");
    }
}


int main()
{
    CSVload csvloader;
    vector<vector<string>> data = csvloader.readCSV("dataset/users.csv");

    for (auto line : data)
    {
        for (auto cell : line)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
