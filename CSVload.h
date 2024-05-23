#ifndef CSVLOAD_H
#define CSVLOAD_H

#include <string>
#include <fstream>
#include <vector>
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream

using namespace std;

class CSVload
{
private:
public:
    CSVload();
    ~CSVload();

    vector<vector<string>>readCSV(string filename);
};

#endif // CSVLOAD_H


    