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
#ifndef DES_OBSERVER_H_
#define DES_OBSERVER_H_

#include <prim/prim.h>

namespace des {

class Observer {
 public:
    // this struct contains the variables passed for progress statistics
  struct ProgressStatistics {
    f64 seconds;
    u64 eventCount;
    u64 ticks;
    f64 eventsPerSecond;
    f64 ticksPerSecond;
    f64 stepsPerSecond;
  };

  // this struct contains the variables passed for summary statistics
  struct SummaryStatistics {
    u64 eventCount;
    u64 timeSteps;
    u64 ticks;
    f64 seconds;
  };

  Observer();
  virtual ~Observer();

  // this is called on every progress update from the simulator
  virtual void progressStatistics(const ProgressStatistics& _progressStats);

  // this is called after the simulation completes
  virtual void summaryStatistics(const SummaryStatistics& _summaryStats);
};

}  // namespace des

#endif  // DES_OBSERVER_H_
