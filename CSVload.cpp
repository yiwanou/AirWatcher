#include "CSVload.h"

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