#pragma once

#include <iostream>

using namespace std;

template<class T>
class TStack {
    size_t lenSt;
    T *pMem;
    size_t top;

public:
    TStack() {
        top = -1;
        lenSt = 1;
        pMem = new T[1]();
    }

    ~TStack() {
        delete[] pMem;
    }

    TStack(TStack &s) {
        lenSt = s.lenSt;
        top = s.top;
        pMem = new T[lenSt];
        for (int i = 0; i < top+1; i++) {
            pMem[i] = s.pMem[i];
        }
    }

    TStack& operator=(TStack &v) {
        if (this != &v) {
            lenSt = v.lenSt;
            top = v.top;
            delete[] pMem;
            pMem = new T[lenSt];
            for (int i = 0; i < top+1; i++) {
                pMem[i] = v.pMem[i];
            }
        }
        return *this;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == lenSt - 1) {
            return true;
        }
        return false;
    }

    void Pop() {
        if (top == -1) {
            throw "out of range";
        }
        top--;
    }

    T Top() {
        if (top == -1)
            throw "out of range";

        return (pMem[top]);
    }

    void Push(T val) {
        if (top == lenSt - 1) {
            T *tmp = new T[lenSt * 2];
            copy(pMem, pMem + lenSt, tmp);
            delete[] pMem;
            pMem = tmp;
            lenSt *= 2;
        }
        top++;
        pMem[top] = val;
    }

    bool operator==(TStack &s) {
        if (top != s.top) {
            return false;
        }
        for (size_t i = 0; i < top; i++) {
            if (pMem[i] != s.pMem[i]) {
                return false;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &ostr, const TStack &v) {
        for (size_t i = 0; i < v.top; i++)
            ostr << v.pMem[i] << ' ';
        return ostr;
    }
};

