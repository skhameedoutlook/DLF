#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Tensor;

class Operation {
    public:
    Tensor *t1, *t2;
    float grad1, grad2;
    string type;

    Operation();
    Operation(Tensor*, Tensor*, string);
    Tensor* execute();
    void backward(float);
};