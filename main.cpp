#include<iostream>
#include<bits/stdc++.h>
#include "libs/Tensor.cpp"

using namespace std;


int main() {
    Tensor a, b, c;
    a.val = 5;
    b.val = 3;
    c = a*a*a;
    c.backward();
    cout << a.grad << endl;

    return 0;
}