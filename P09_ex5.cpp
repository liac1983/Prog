#include <iostream>
#include <iomanip>
#include "Stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack(): size_(0), top_(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (top_ != nullptr) {
        node<T> *prev = top_;
        top_ = top_->next;
        delete prev;
    }
}
template<typename T>
size_t Stack<T>::size() const {
    return size_;
}

template<typename T>
bool Stack<T>::peek(T &elem) const {
    if (top_ != nullptr) {
        elem = top_->value;
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool Stack<T>::pop(T &elem) {
    if (top_ != nullptr) {
        elem = top_->value;
        node<T> *temp = top_;
        top_ = top_->next;
        delete temp;
        size_--; 
        return true;
    } else {
        return false;
    }
}

template<typename T>
void Stack<T>::push(const T &elem) {
    node<T> *new_node = new node<T>;
    new_node->next = top_;
    new_node->value = elem;
    top_ = new_node;
    size_++;
}


int main() {
    	
Stack<int> s;
const Stack<int>& r = s;
int v = -1;
cout << r.size()  << ' ' << boolalpha
     << r.peek(v) << ' ' << v << ' '
     << s.pop(v)  << ' ' << v << ' '
     << s.size() << '\n';
    return 0;
}
