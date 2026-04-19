#include <iostream>
#include <string>
using namespace std;


class Integer{
    private:
    int val;
    public:
    Integer(int);
    Integer(Integer*);
    friend Integer operator+(const Integer &num1, const Integer &num2);
    friend Integer operator+(const Integer &num1, const int value);
    void print();
};

void Integer::print() {
    cout << this->val << endl;
}
Integer::Integer(int a){
    this->val = a;
}
Integer::Integer(Integer *other){
    if (other != nullptr){
        this->val = other->val;
    }
    else{
        this->val = 0;
    }
}
Integer operator+(const Integer &num1, const Integer &num2){

    return num1.val + num2.val;

}
Integer operator+(const Integer &num1, const int value){
    return num1.val + value;
}
template<class T> class Cell {
protected:
    T infor;
public:
    void set(T _infor) { this->infor = _infor; };
    T get() { return this->infor; };
};

enum Color {White, Yellow, Black, Red, Blue};

template <class T>
class ColoredCell : public Cell<T>{
    private:
      Color color;
    public:
      void setColor(Color c){
        this->color = c;
      }
      Color getColor(){
        return this->color;
      }
      T* get(){
        if (this->color != White){
            return &(this->infor);
        }
        else{
            return nullptr;
        }
      }
};
template <typename T>
class Array {
public:
    Array(int size, T initValue);
    

    void setAt(int idx, const T & value);
    T getAt(int idx);
    
    void print();

private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

template <typename T>
Array<T>::Array(int size, T initValue){
    this->size = size;
    this->p[0] = initValue;
}
template <typename T>
void Array<T>::setAt(int idx, const T& value){
    if (idx < 0 || idx >= this->size) throw -1;
    this->p[idx] = value;
}
template <typename T>
T Array<T>::getAt(int idx){
    return this->p[idx];
}
int main () {
    Array<int> * a7 = new Array<int>(10, 2);
    a7->print();
    try {
        a7->setAt(-1, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(10, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(2, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    delete a7;
}