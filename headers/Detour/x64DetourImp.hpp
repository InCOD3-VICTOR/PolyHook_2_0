//
// Created by steve on 7/4/17.
//

#ifndef POLYHOOK_2_X64DETOURIMPL_HPP
#define POLYHOOK_2_X64DETOURIMPL_HPP

#include "headers/Maybe.hpp"
#include "headers/MemoryAllocation/RangeAllocator.hpp"
#include "headers/IHook.hpp"

#include <memory>
#include <vector>

namespace PLH {

class x64DetourImp
{
public:
    //TODO: Make the allocator typedef a template argument to class
    typedef PLH::RangeAllocator<uint8_t, PLH::MemAllocatorUnix> LinuxAllocator;
    typedef std::vector<uint8_t, LinuxAllocator>                DetourBuffer;

    PLH::Maybe<DetourBuffer> AllocateMemory(const uint64_t Hint);

    PLH::HookType GetType() const;

    PLH::Mode GetArchType() const;

    uint8_t minimumPrologueLength() const;

    uint8_t preferedPrologueLength() const;

    std::shared_ptr<PLH::Instruction> makeMinimumSizeJump(const uint64_t address, const uint64_t destination) const;

    std::shared_ptr<PLH::Instruction> makePreferedSizeJump(const uint64_t address, const uint64_t destination) const;
};
}
#endif //POLYHOOK_2_X64DETOURIMPL_HPP
