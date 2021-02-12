#include "Operation.h"
#include "Tensor.h"

class SubtractOperation: public Operation {
    public:
    Tensor *t1, *t2;
    float grad1, grad2;
    char type;

    SubtractOperation() {
        this->t1 = NULL;
        this->t2 = NULL;
    }
    SubtractOperation(Tensor* t1, Tensor* t2) {
        this->t1 = t1;
        this->t2 = t2;
    }
    Tensor* execute() {
        if(this->t1 == NULL || this->t2 == NULL) {
            return NULL;
        }
        return new Tensor(this->t1->val-this->t2->val);
    }
    void backward(float grad) {
        if(t1 == t2) {
            t1->backward(0);
        }
        else {
            t1->backward(grad*1);
            t2->backward(grad*-1);
        }
    }
};

