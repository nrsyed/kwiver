/*ckwg +29
 * Copyright 2018 by Kitware, Inc.
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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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

#ifndef VITAL_RANGE_TRANSFORM_H
#define VITAL_RANGE_TRANSFORM_H

#include <vital/range/defs.h>

#include <functional>

namespace kwiver {
namespace vital {
namespace range {

// ----------------------------------------------------------------------------
/// Transforming range adapter.
/**
 * This range adapter applies a transformation to the elements of a range.
 */
template < typename TransformedValue, typename Range >
class transform_view
{
protected:
  using range_iterator_t = decltype( std::declval< Range const >().begin() );
  using range_value_ref_t = decltype( *( std::declval< range_iterator_t >() ) );

public:
  using value_t = TransformedValue;
  using transform_function_t = std::function< value_t ( range_value_ref_t ) >;

  class const_iterator
  {
  public:
    const_iterator( const_iterator const& ) = default;
    const_iterator& operator=( const_iterator const& ) = default;

    bool operator!=( const_iterator const& other ) const
    { return m_iter != other.m_iter; }

    value_t operator*() const {  return m_func( *m_iter ); }

    const_iterator& operator++() { ++m_iter; return *this; }

  protected:
    friend class transform_view;
    const_iterator( range_iterator_t const& iter,
                    transform_function_t const& func )
      : m_iter{ iter }, m_func( func ) {}

    range_iterator_t m_iter;
    transform_function_t const& m_func;
  };

  transform_view( Range const& range, transform_function_t func )
    : m_range( range ), m_func{ func } {}

  const_iterator begin() const { return { m_range.begin(), m_func }; }
  const_iterator end() const { return { m_range.end(), m_func }; }

protected:
  Range const& m_range;
  transform_function_t m_func;
};

///////////////////////////////////////////////////////////////////////////////

// ----------------------------------------------------------------------------
template < typename Functor >
struct transform_view_adapter_t
{
  using value_t = typename function_detail< Functor >::return_type_t;

  template < typename Range >
  transform_view< value_t, Range >
  adapt( Range const& range ) const
  { return { range, m_func }; }

  Functor m_func;
};

KWIVER_RANGE_ADAPTER_FUNCTION( transform )

} } } // end namespace

#endif
