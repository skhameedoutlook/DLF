#pragma once
#include<iostream>

using namespace std;

class B;

class A {
    public:
    int a;
    B* b;

    A();
    void displaya(int);
};
