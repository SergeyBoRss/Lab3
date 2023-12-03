//
// Created by Sergey on 03.12.2023.
//

#ifndef LAB3_POSTFIX_H
#define LAB3_POSTFIX_H

#include "TStack.h"
#include <string>
#include <map>
#include <vector>
#include <cctype>

class TArithmeticExpression {
    string infix;
    string postfix;


    map<string, int> priority;
    vector<string> lexems;
public:
    TArithmeticExpression(string infx) : infix(infx) {
        priority = {{"+", 1},
                    {"-", 1},
                    {"*", 2},
                    {"/", 2},};
    }


    string GetInfix() { return infix; }

    string GetPostfix() { return postfix; }

    void Parse() {
        string st = infix;
        string tmp = "";

        for (auto i: st) {
            if (isdigit(i) || i == '.') {
                tmp += i;
            } else {
                if (tmp.empty()) {
                    throw "Not nums";
                }

                lexems.push_back(tmp);
                tmp = i;
                lexems.push_back(tmp);
                tmp = "";
            }
        }
        lexems.push_back(tmp);
    }

    string ToPostfix() {
        TStack<string> st;
        string tmp = "";

        for (string item: lexems) {
            if (item == "(") {
                st.Push(item);
            } else if (item == ")") {
                tmp = st.Top();
                st.Pop();
                while (tmp != "(") {
                    postfix += tmp += " ";
                    tmp = st.Top();
                    st.Pop();
                }
            } else if (item == "+" || item == "-" || item == "*" || item == "/") {
                while (!st.isEmpty()) {
                    tmp = st.Top();
                    st.Pop();
                    if (priority[item] <= priority[tmp]) {
                        postfix += tmp += " ";
                    } else {
                        st.Push(tmp);
                        break;
                    }
                }
                st.Push(item);
            } else {
                postfix += item += " ";
            }
        }
        cout << "\n";
        while (!st.isEmpty()) {
            tmp = st.Top();
            st.Pop();
            postfix += tmp += " ";
        }
    }

    double Calculate()
};


#endif //LAB3_POSTFIX_H
