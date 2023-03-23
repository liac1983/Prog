#include "svnode.cpp"
#include <iostream>
using namespace std;

// Creates a new sparse v-ector representing the sum of a and b
svnode* sum(const svnode* a, const svnode* b) {
    if(a == nullptr && b == nullptr)
        return nullptr;
    svnode* result = nullptr;
    svnode* curr = nullptr;
    while (a != nullptr && b != nullptr) {
        // node created in this iteration if any
        svnode* n = nullptr;

        //handle 3 possible cases
        if(a -> position < b -> position) {
            n = new svnode {a -> position, a -> value, nullptr};
            a = a -> next;
        }
        else if (a -> position > b -> position) {
            n = new svnode { b -> position, b -> value, nullptr};
            b = b -> next;
        } else {
            // Same position for a and b
            int v = a -> value + b -> value;
            if (v != 0) {
                // Do not store 0
                n = new svnode { a -> position, v, nullptr};
            }
            a = a -> next; b = b -> next;
        }
        if (n != nullptr) {
            if (result  == nullptr) result = n;
            else curr -> next  = n;
            curr = n;
        }
    }
    // copy remaining nodes in a, if any
    while (a != nullptr) {
        svnode* n = new svnode { a -> position, a -> value, nullptr};
        if (result  == nullptr) result  = n;
        else curr -> next = n;
        curr = n;
        a = a -> next;
    }
    //copy remaining nodes in b, if any
    while (b != nullptr) {
        svnode* n = new svnode {b -> position, b -> value, nullptr};
        if (result  == nullptr) result  = n;
        else curr -> next  = n;
        curr  = n;
        b = b -> next;
    }
    return result;
}

int main(){
svnode* a = nullptr;
svnode* b = nullptr;
svnode* c = sum(a, b);
print(a); print(b); print(c); cout << '\n';
destroy(a); destroy(b); destroy(c);
    return 0;
}