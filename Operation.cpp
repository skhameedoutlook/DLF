#include "Operation.h"
#include "Tensor.h"

Operation::Operation() {
    this->t1 = NULL;
    this->t2 = NULL;
}

Operation::Operation(Tensor* t1, Tensor* t2, string type) {
    this->t1 = t1;
    this->t2 = t2;
    this->type = type;
}

Tensor* Operation::execute() {
    if(this->t1 == NULL || this->t2 == NULL) {
        return NULL;
    }
    if(this->type.compare("Add") == 0) {
        return new Tensor(this->t1->val+this->t2->val);
    }
    else if(this->type.compare("Multiply") == 0) {
        return new Tensor(this->t1->val*this->t2->val);
    }
    return new Tensor();
}

void Operation::backward(float grad) {
    if(this->type.compare("Add") == 0) {
        t1->backward(grad*1);
        t2->backward(grad*1);
    }
    else if(this->type.compare("Multiply") == 0) {
        if(t1 == t2) {
            t1->backward(grad*2*t1->val);
            t2->backward(grad*2*t1->val);
        }
        else {
            t1->backward(grad*t2->val);
            t2->backward(grad*t1->val);
        }
    }
}