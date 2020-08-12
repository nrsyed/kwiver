/*ckwg +29
 * Copyright 2012-2017, 2020 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SPROKIT_PROCESSES_EXAMPLES_FLOW_DEPENDENT_PROCESS_H
#define SPROKIT_PROCESSES_EXAMPLES_FLOW_DEPENDENT_PROCESS_H

#include "processes_examples_export.h"

#include <sprokit/pipeline/process.h>

/**
 * \file flow_dependent_process.h
 *
 * \brief Declaration of the flow dependent process.
 */

namespace sprokit {

/**
 * \class flow_dependent_process
 *
 * \brief A process with flow dependent ports.
 *
 * \process A process with flow dependent ports.
 *
 * \configs
 *
 * \config{reject} Whether to reject the set type or not.
 *
 * \iports
 *
 * \iport{input} A flow dependent input port.
 *
 * \oports
 *
 * \oport{output} A flow dependent output port.
 *
 * \ingroup examples
 */
class PROCESSES_EXAMPLES_NO_EXPORT flow_dependent_process : public process {
public:
  PLUGIN_INFO( "flow_dependent",
               "A process with a flow dependent type" );
  /**
   * \brief Constructor.
   *
   * \param config The configuration for the process.
   */
  flow_dependent_process(kwiver::vital::config_block_sptr const &config);
  /**
   * \brief Destructor.
   */
  ~flow_dependent_process();

protected:
  /**
   * \brief Reset the process.
   */

  void _reset() override;
  /**
   * \brief Step the process.
   */
  void _step() override;

  /**
   * \brief Set the type for an input port.
   *
   * \param port The name of the port.
   * \param new_type The type of the connected port.
   *
   * \returns True if the type can work, false otherwise.
   */
  bool _set_input_port_type(port_t const &port, port_type_t const &new_type) override;

  /**
   * \brief Set the type for an output port.
   *
   * \param port The name of the port.
   * \param new_type The type of the connected port.
   *
   * \returns True if the type can work, false otherwise.
   */
  bool _set_output_port_type(port_t const &port, port_type_t const &new_type) override;

private:
  void make_ports();

  class priv;
  std::unique_ptr<priv> d;
};
}

#endif // SPROKIT_PROCESSES_EXAMPLES_FLOW_DEPENDENT_PROCESS_H
