#include "node.cpp"

node* reverse(const node* n) {
    if (n == nullptr) {
        return nullptr;
    }
    node* r = new node { n -> value, nullptr, nullptr };
    n = n -> next;
    while (n != nullptr) {
        r -> prev = new node { n -> value, nullptr, r };
        r = r -> prev;
        n = n -> next;
    }
    return r;
}

int main() {
node* a = build(1, nullptr);
node* b = reverse(a);
print(b);
destroy(a); destroy(b);
    return 0;
}