#include "Operation.h"
#include "Tensor.h"
#include "Operation.cpp"
#include "MultiplyOperation.cpp"
#include "AddOperation.cpp"
#include "SubtractOperation.cpp"
#include "DivideOperation.cpp"

Tensor::Tensor() {
    this->val = 0;
    this->grad = 0;
    this->type = "float";
    this->op = NULL;
    this->oper = '\0';
}

Tensor::Tensor(float val) {
    this->val = val;
    this->grad = 0;
    this->type = "float";
    this->op = NULL;
    this->oper = '\0';
}

Tensor Tensor::operator*(Tensor& second) {
    MultiplyOperation* op_node = new MultiplyOperation(this, &second);
    Tensor* result = op_node->execute();
    result->op = op_node;
    result->oper = '*';
    return *result;
}

Tensor Tensor::operator+(Tensor& second) {
    AddOperation* op_node = new AddOperation(this, &second);
    Tensor* result = op_node->execute();
    result->op = op_node;
    result->oper = '+';
    return *result;
}

Tensor Tensor::operator-(Tensor& second) {
    SubtractOperation* op_node = new SubtractOperation(this, &second);
    Tensor* result = op_node->execute();
    result->op = op_node;
    result->oper = '-';
    return *result;
}


Tensor Tensor::operator/(Tensor& second) {
    DivideOperation* op_node = new DivideOperation(this, &second);
    Tensor* result = op_node->execute();
    result->op = op_node;
    result->oper = '/';
    return *result;
}

void Tensor::backward() {
    if(this->op == NULL) {
        return;
    }
    this->backward(1);
}

void Tensor::backward(float grad) {
    this->grad += grad;
    cout << "new grad " << this->grad << ", number " << this->val << endl;
    if(this->op == NULL) {
        return;
    }
    this->op->backward(grad);

}