#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
T GetInput(string inputMessage);

int main()
{
    int value = GetInput<int>("Please enter a number so it can be sorted");
    string strValue = to_string(value);
    sort(strValue.begin(), strValue.end(), greater<char>());
    int sortedValue = stoi(strValue);
    if (sortedValue == value)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << sortedValue << endl;
    }
}
template <typename T>
T GetInput(string inputMessage)
{
    T userInput;
    while (true)
    {
        cout << inputMessage << endl << endl;
        string rawInput;
        getline(cin, rawInput);
        try
        {
            istringstream iss(rawInput);
            iss >> userInput;
            if (iss.fail() && iss.peek() != EOF)
            {
                throw logic_error("This is not the right data type");
            }
            break;
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl << endl;
        }
    }
    return userInput;
}
