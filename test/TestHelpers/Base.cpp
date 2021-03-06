///////////////////////////////////////////////////////////////////
//
// Copyright 2014 Felix Petriconi
//
// License: http://boost.org/LICENSE_1_0.txt, Boost License 1.0
//
// Authors: http://petriconi.net, Felix Petriconi
//
///////////////////////////////////////////////////////////////////
#include <gtest/gtest.h>
#include "Base.h"

void alb::test_helpers::EXPECT_MEM_EQ(void *a, void *b, size_t n)
{
  auto isDifferentAt = ::memcmp(a, b, n);
  EXPECT_EQ(0, isDifferentAt) << "Memory is different at offset: " << isDifferentAt
                              << ". Should be " << (int)*(static_cast<char *>(b) + isDifferentAt)
                              << " but should be "
                              << (int)*(static_cast<char *>(a) + isDifferentAt);
}

std::atomic<size_t> alb::test_helpers::TestMallocator::_allocatedMem;
