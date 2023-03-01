#include <iostream>
#include "MemoryPool.h"

int main() {
  MemoryPool pool {sizeof(int), 10};

  int* p1 = static_cast<int*>(pool.allocate());
  std::cout << "p1 allocated to: " << *p1 << std::endl;
  *p1 = 42;
  std::cout << "p1 allocated to: " << *p1 << std::endl;

  int* p2 = static_cast<int*>(pool.allocate());
  std::cout << "p2 allocated to: " << *p2 << std::endl;
  *p2 = 108;
  std::cout << "p2 allocated to: " << *p2 << std::endl;

  pool.deallocate(p1);
  pool.deallocate(p2);

  return 0;
}
