/*
 * Copyright (c) 2021, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Vector.h>
#include <LibJS/Forward.h>

namespace JS {

class BlockAllocator {
public:
    BlockAllocator();
    ~BlockAllocator();

    void* allocate_block(char const* name);
    void deallocate_block(void*);

private:
    static constexpr size_t max_cached_blocks = 64;

    Vector<void*> m_blocks;
};

}
