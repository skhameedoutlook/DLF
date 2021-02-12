#include "Operation.h"
#include "Tensor.h"

class MultiplyOperation: public Operation {
    public:
    Tensor *t1, *t2;
    float grad1, grad2;
    char type;

    MultiplyOperation() {
        this->t1 = NULL;
        this->t2 = NULL;
    }
    MultiplyOperation(Tensor* t1, Tensor* t2) {
        this->t1 = t1;
        this->t2 = t2;
    }
    Tensor* execute() {
        if(this->t1 == NULL || this->t2 == NULL) {
            return NULL;
        }
        
        return new Tensor(this->t1->val*this->t2->val);
    }
    void backward(float grad) {
        if(t1 == t2) {
            cout << "HERE" << endl;
            t1->backward(grad*2*t1->val);
        }
        else {
            t1->backward(grad*t2->val);
            t2->backward(grad*t1->val);
        }
    }
};

