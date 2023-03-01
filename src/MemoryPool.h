#ifndef _MEMORY_POOL_
#define _MEMORY_POOL_

#include <vector>

class MemoryPool {
public:
  MemoryPool(size_t block_size, size_t num_blocks);

  void* allocate();

  void deallocate(void* ptr);

private:
  size_t m_block_size;
  size_t m_num_blocks;
  std::vector<char> m_data;
  std::vector<void*> m_freelist;
};

#endif // _MEMORY_POOL_
