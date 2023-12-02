#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include <sstream>
using namespace std;

void findFunctionNames(const string& codeLine, unordered_set<string>& uniqueFuncNames)
{
    istringstream lineStream(codeLine);
    string token;
    while (lineStream >> token)
        {
        if (token == "int" || token == "void")
            {

            lineStream >> token;

            size_t pos = token.find('(');

            if (pos != string::npos && token != "main()")
            {
                uniqueFuncNames.insert(token.substr(0, pos));
            }

            }
    }
}

void findOperators(const string& codeLine, unordered_set<string>& uniqueOperators) {
               if (codeLine.find('=') != string::npos)
               {
                 uniqueOperators.insert("assign");
               }

    if (codeLine.find('+') != string::npos)
    {
        uniqueOperators.insert("add");
    }

    if (codeLine.find('-') != string::npos)
    {
        uniqueOperators.insert("subtract");
    }

    if (codeLine.find('*') != string::npos)
    {
        uniqueOperators.insert("multiply");
    }

                      if (codeLine.find('/') != string::npos)
                       {
                        uniqueOperators.insert("divide");
                        }


}

int main() {
    ifstream codeFile("source_code.txt");
    if (!codeFile.is_open())
        {
        cerr << "Error opening file!" << endl;
        return 1;
        }

    unordered_set<string> uniqueFuncNames;


    unordered_set<string> uniqueOperators;


    string line;


    while (getline(codeFile, line))
    {

        findFunctionNames(line, uniqueFuncNames);

        findOperators(line, uniqueOperators);
    }


    codeFile.close();

    cout << "Total Functions:" << endl;

    int funcCount = 0;

    for (const auto& funcName : uniqueFuncNames)
        {

        cout << "Function " << ++funcCount << ": " << funcName << endl;

        }
    cout << "Total  User Defined  functions: " << funcCount-1<< endl;

    cout << "\nUnique Operators:" << endl;

    int opCount = 0;

    for (const auto& op : uniqueOperators)
    {

        cout << "Operator-" << ++opCount << ": " << op << endl;
    }


    cout << "Total number of unique operators: " << opCount << endl;

    return 0;
}

