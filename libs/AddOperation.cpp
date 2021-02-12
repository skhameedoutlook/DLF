#include "Operation.h"
#include "Tensor.h"

class AddOperation: public Operation {
    public:
    Tensor *t1, *t2;
    float grad1, grad2;
    char type;

    AddOperation() {
        this->t1 = NULL;
        this->t2 = NULL;
    }
    AddOperation(Tensor* t1, Tensor* t2) {
        this->t1 = t1;
        this->t2 = t2;
    }
    Tensor* execute() {
        if(this->t1 == NULL || this->t2 == NULL) {
            return NULL;
        }
        return new Tensor(this->t1->val+this->t2->val);
    }
    void backward(float grad) {
        if(t1 == t2) {
            t1->backward(grad*2);
        }
        else {
            t1->backward(grad*1);
            t2->backward(grad*1);
        }
    }
};

