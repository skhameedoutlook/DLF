#include<iostream>
#include<bits/stdc++.h>
#include "Tensor.cpp"

using namespace std;


int main() {
    Tensor a, b, c;
    a.val = 2;
    b.val = 3;
    c = a*b;
    cout << c.val << endl;
    cout << c.op->t1->val<<endl;
    cout << c.op->t2->val<<endl;
    cout << c.op->type<<endl;
    c.backward();

    return 0;
}