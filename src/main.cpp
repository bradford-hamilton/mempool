#include <iostream>
#include "MemoryPool.h"

int main() {
  MemoryPool pool {sizeof(int), 10};

  int* p1 = static_cast<int*>(pool.allocate());
  int* p2 = static_cast<int*>(pool.allocate());

  *p1 = 50;
  *p2 = 100;

  std::cout << *p1 << std::endl;
  std::cout << *p2 << std::endl;

  pool.deallocate(p1);
  pool.deallocate(p2);

  return 0;
}
