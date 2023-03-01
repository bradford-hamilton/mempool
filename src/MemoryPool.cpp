#include <iostream>
#include <vector>
#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t block_size, size_t num_blocks)
    : m_block_size{block_size}, m_num_blocks{num_blocks}
{
    m_data.reserve(m_block_size * m_num_blocks);

    for (size_t i = 0; i < m_num_blocks; ++i) {
      m_freelist.push_back(&m_data[i*m_block_size]);
    }
}

void* MemoryPool::allocate() {
  if (m_freelist.empty()) {
    return nullptr;
  }

  void* ptr = m_freelist.back();
  m_freelist.pop_back();

  return ptr;
}

void MemoryPool::deallocate(void* ptr) {
  m_freelist.push_back(ptr);
}
