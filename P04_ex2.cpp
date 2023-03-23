#include "node.cpp"

//   Removes the first occurrence of value in the node list
node* remove(int value, node* n)   {
    node* curr = n;
    node* prev = nullptr;
    while (curr != nullptr && curr -> value != value)   {
        prev = curr;
        curr = curr -> next;
    }
    if (curr != nullptr)    {
        //value found
        if (prev == nullptr)    {
            //value in the first node
            n = curr -> next;
        } else {
            prev -> next = curr -> next;
        }
        delete curr;
    }
    return n;
}

int main(){
	
node* n = nullptr;
n = remove(0, n);
print(n);
destroy(n);
    return 0;
}