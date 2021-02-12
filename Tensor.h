#pragma once
#include "Operation.h"

class Tensor {
    public:
    float val;
    float grad;
    Operation* op;
    string type;

    Tensor();
    Tensor(float val);
    Tensor operator * (Tensor&);
    Tensor operator + (Tensor&);
    void backward();
    void backward(float);

};