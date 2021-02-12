#include "Operation.h"
#include "Tensor.h"
#include "Operation.cpp"

Tensor::Tensor() {
    this->val = 0;
    this->grad = 0;
    this->type = "float";
    this->op = NULL;
}

Tensor::Tensor(float val) {
    this->val = val;
    this->grad = 0;
    this->type = "float";
    this->op = NULL;
}

Tensor Tensor::operator*(Tensor& second) {
    Operation* op_node = new Operation(this, &second, "Multiply");
    Tensor* result = op_node->execute();
    result->op = op_node;
    return *result;
}

Tensor Tensor::operator+(Tensor& second) {
    Operation* op_node = new Operation(this, &second, "Add");
    Tensor* result = op_node->execute();
    result->op = op_node;
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