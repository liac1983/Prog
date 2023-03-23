#include "node.cpp"

//! Remove nodes until nod with the given value.
node* remove_until(node* n, int v) {
  while (n != nullptr && n->value != v) {
    node* tmp = n->next;
    delete n; 
    n = tmp;
  }
  if (n != nullptr) {
    n->prev = nullptr;
  }
  return n;
}


int main() {
    node* n = build(1, nullptr);
int v = 1;
n = remove_until(n, v);
print(n);
destroy(n); 
    return 0;
}

