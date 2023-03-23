#include "dlnode.cpp"

// Insert a node with value before the pos-th node in the chain
dlnode* insert(dlnode* dln, int pos, int value) {
    if (pos == 0)   {
        dlnode* new_node = new dlnode{value, nullptr, dln};
        if(dln != nullptr)  {dln -> prev = new_node; }
        return new_node;
    }
    dlnode* curr = dln;
    dlnode* prev;
    do  {
        prev = curr;
        curr = curr -> next;
        pos--;
    } while (pos > 0);
    prev -> next = new dlnode {value, prev, curr };
    if (curr != nullptr) {curr -> prev = prev -> next; }
    return dln;
}

int main(){
dlnode* dln = nullptr;
dln = insert(dln, 0, 0);
print(dln); destroy(dln);
    return 0;
}