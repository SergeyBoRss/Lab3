//
// Created by Sergey on 03.12.2023.
//
#include "TStack.h"
#include "postfix.h"
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {
    string infix;
    string postfix;

    map<string, int> priority;
    vector<double> nums;
    vector<string> lexems;
    string st = "2++3";


    TArithmeticExpression test(st);
    cout << test.ToPostfix() << endl;
    for (auto i:test.GetLexs())
        cout << i << " ";
    cout << test.Calculate();
}