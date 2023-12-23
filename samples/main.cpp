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

    string st;
    cout << "Enter expression:";
    cin >> st;

    TArithmeticExpression now(st);
    cout << "Infix form: \n" << now.GetInfix() << endl;
    cout << "Postfix form: " << now.ToPostfix() << endl;
    cout << "Calculate: " << now.Calculate() << endl;
}