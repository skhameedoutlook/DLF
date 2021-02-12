#include<iostream>
#include<bits/stdc++.h>
#include "libs/Tensor.cpp"

using namespace std;

int main() {
    Tensor a, b, c;
    Tensor w, x, y;
    w.val = 1;
    x.val = 2;
    y.val = 3;
    Tensor ans = w*x;
    Tensor ans2 = ans-y;
    Tensor ans3 = ans2 * ans2;
    Tensor ans4 = w*w;
    Tensor ans5 = ans3 + ans4;
    ans5.backward();
    cout << w.grad << endl;

    return 0;
}