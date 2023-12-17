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

    vector <string> infLexems;
    map<string, int> priority;
    vector <string> lexems;
public:
    TArithmeticExpression(string infx) : infix(infx) {
        int c = 0;

        for (char i : infix) {
            if (i == '(') {
                c++;
            } else if (i == ')') {
                c--;
                if (c < 0) {
                    throw runtime_error("incorrect brackets");
                }
            }
        }
        if (c != 0) {
            throw runtime_error("incorrect brackets");
        }

        priority = {{"+", 1},
                    {"-", 1},
                    {"*", 2},
                    {"/", 2},};
    }


    string GetInfix() { return infix; }

    string GetPostfix() { return postfix; }

    vector <string> GetLexs() { return infLexems; }

    void ParseInf() {
        string st = infix;
        string tmp = "";

        for (auto i : st) {
            if (isdigit(i) || i == '.') {
                tmp += i;
            } else if (i == '+' || i == '-' || i == '*' || i == '/') {
                if (!tmp.empty()) {
                    lexems.push_back(tmp);
                    tmp = "";
                }
                lexems.push_back(string(1, i));
            } else if (i == '(' || i == ')') {
                if (!tmp.empty()) {
                    lexems.push_back(tmp);
                    tmp = "";
                }
                lexems.push_back(string(1, i));
            } else if (i != ' ') {
                throw runtime_error("Incorrect");
            }
        }

        if (!tmp.empty()) {
            lexems.push_back(tmp);
        }
    }



    string ToPostfix() {
        this->ParseInf();
        TStack<string> st;
        string tmp = "";

        for (string item: lexems) {
            if (item == "(") {
                st.Push(item);
            } else if (item == ")") {
                tmp = st.Top();
                st.Pop();
                while (tmp != "(") {
                    postfix += tmp;
                    postfix += " ";
                    infLexems.push_back(tmp);
                    tmp = st.Top();
                    st.Pop();
                }
            } else if (item == "+" || item == "-" || item == "*" || item == "/") {
                while (!st.isEmpty()) {
                    tmp = st.Top();
                    st.Pop();
                    if (priority[item] <= priority[tmp]) {
                        postfix += tmp;
                        postfix += " ";
                        infLexems.push_back(tmp);
                    } else {
                        st.Push(tmp);
                        break;
                    }
                }
                st.Push(item);
            } else {
                postfix += item;
                postfix += " ";
                infLexems.push_back(item);
            }
        }
        cout << "\n";
        while (!st.isEmpty()) {
            tmp = st.Top();
            st.Pop();
            postfix += tmp;
            postfix += " ";
            infLexems.push_back(tmp);
        }
        return postfix;
    }

    double Calculate() {
        TStack<double> st;
        double rOp;
        double lOp;
        for (auto lexem: infLexems) {
            if (lexem == "+" || lexem == "-" || lexem == "*" || lexem == "/") {
                if (!st.isEmpty()) {
                    rOp = st.Top();
                    st.Pop();
                } else {
                    throw runtime_error("No right argument");
                }
                if (!st.isEmpty()) {
                    lOp = st.Top();
                    st.Pop();
                } else {
                    throw runtime_error("No left argument");
                }


                if (lexem == "+") {
                    st.Push(lOp + rOp);
                } else if (lexem == "-") {
                    st.Push(lOp - rOp);
                } else if (lexem == "*") {
                    st.Push(lOp * rOp);
                } else if (lexem == "/") {
                    st.Push(lOp / rOp);
                }
            } else {
                st.Push(stod(lexem));
            }
        }
        return st.Top();
    }
};


#endif //LAB3_POSTFIX_H
