#include "alist.cpp"

void append(alist* a, const alist* b) {
  if (b -> size == 0)
    return; // b is the empty list
  
  //  Create new array of elements
  int new_size = a -> size + b -> size;
  int* new_elements = new int[new_size];

  //   Copy values from a and b
  for (int i = 0; i < a -> size; i++) {
    new_elements[i] = a -> elements[i];
  }
  for (int i = 0; i < b -> size; i++) {
    new_elements[a -> size +i] = b -> elements[i];
  }
  //  Delete old array
  delete [] a -> elements;

  //  Point to new array
  a -> size = new_size;
  a -> elements = new_elements;
}

int main()  {
alist* a = empty();
const int nB = 2;
int eB[nB] = { 1, 2 };
const alist* b = build(nB, eB);
append(a, b);
print(a);
destroy(a);
destroy(b);
  return 0;
}