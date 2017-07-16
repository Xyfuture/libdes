/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * - Neither the name of prim nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior
 * written permission.
 *
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "des/Clocked.h"

#include <cassert>

#include "des/Simulator.h"

namespace des {

Clocked::Clocked(const std::string& _name, const Clocked* _parent)
    : Component(_name, _parent), cyclePeriod_(_parent->cyclePeriod_),
      cyclePhase_(_parent->cyclePhase_) {
  assert(cyclePhase_ < cyclePeriod_);
}

Clocked::Clocked(const std::string& _name, const Component* _parent,
                 Tick _cyclePeriod, Tick _cyclePhase)
    : Component(_name, _parent), cyclePeriod_(_cyclePeriod),
      cyclePhase_(_cyclePhase) {
  assert(cyclePhase_ < cyclePeriod_);
}

Clocked::Clocked(Simulator* _simulator, const std::string& _name,
                 Tick _cyclePeriod, Tick _cyclePhase)
    : Component(_simulator, _name), cyclePeriod_(_cyclePeriod),
      cyclePhase_(_cyclePhase) {
  assert(cyclePhase_ < cyclePeriod_);
}

Clocked::~Clocked() {}

Tick Clocked::cyclePeriod() const {
  return cyclePeriod_;
}

Tick Clocked::cyclePhase() const {
  return cyclePhase_;
}

Tick Clocked::futureCycle(u32 _cycles) const {
  assert(_cycles > 0);
  Tick tick = simulator->time().tick();
  Tick rem = tick % cyclePeriod_;
  if (rem != cyclePhase_) {
    tick += (cyclePhase_ - rem);
    if (rem > cyclePhase_) {
      tick += cyclePeriod_;
    }
    _cycles--;
  }
  return tick + (cyclePeriod_ * _cycles);
}

}  // namespace des
