/*ckwg +29
 * Copyright 2020 by Kitware, Inc.
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

/**
 * \file estimate_essential_matrix_trampoline.txx
 *
 * \brief trampoline for overriding virtual functions for
 *        \link kwiver::vital::algo::estimate_essential_matrix \endlink
 */

#ifndef ESTIMATE_ESSENTIAL_MATRIX_TRAMPOLINE_TXX
#define ESTIMATE_ESSENTIAL_MATRIX_TRAMPOLINE_TXX

#include <python/kwiver/vital/util/pybind11.h>
#include <python/kwiver/vital/algo/trampoline/algorithm_trampoline.txx>
#include <vital/algo/estimate_essential_matrix.h>
#include <vital/types/vector.h>

namespace kwiver {
namespace vital  {
namespace python {
template< class algorithm_def_eem_base=
           kwiver::vital::algorithm_def<
               kwiver::vital::algo::estimate_essential_matrix > >
class algorithm_def_eem_trampoline :
      public algorithm_trampoline< algorithm_def_eem_base>
{
  public:
    using algorithm_trampoline< algorithm_def_eem_base >::algorithm_trampoline;

    std::string type_name() const override
    {
      VITAL_PYBIND11_OVERLOAD(
        std::string,
        kwiver::vital::algorithm_def<
              kwiver::vital::algo::estimate_essential_matrix >,
        type_name,
      );
    }
};


template< class estimate_essential_matrix_base =
                  kwiver::vital::algo::estimate_essential_matrix >
class estimate_essential_matrix_trampoline :
      public algorithm_def_eem_trampoline< estimate_essential_matrix_base >
{
  public:
    using algorithm_def_eem_trampoline< estimate_essential_matrix_base >::
              algorithm_def_eem_trampoline;

    kwiver::vital::essential_matrix_sptr
      estimate(const kwiver::vital::feature_set_sptr feat1,
               const kwiver::vital::feature_set_sptr feat2,
               const kwiver::vital::match_set_sptr matches,
               const kwiver::vital::camera_intrinsics_sptr cal1,
               const kwiver::vital::camera_intrinsics_sptr cal2,
               std::vector<bool>& inliers,
               double inlier_scale)  const override
    {
      VITAL_PYBIND11_OVERLOAD_PURE(
        kwiver::vital::essential_matrix_sptr,
        kwiver::vital::algo::estimate_essential_matrix,
        estimate,
        feat1,
        feat2,
        matches,
        cal1,
        cal2,
        inliers,
        inlier_scale
      );
    }

    kwiver::vital::essential_matrix_sptr
      estimate(const kwiver::vital::feature_set_sptr feat1,
               const kwiver::vital::feature_set_sptr feat2,
               const kwiver::vital::match_set_sptr matches,
               const kwiver::vital::camera_intrinsics_sptr cal,
               std::vector<bool>& inliers,
               double inlier_scale)  const override
    {
      VITAL_PYBIND11_OVERLOAD_PURE(
        kwiver::vital::essential_matrix_sptr,
        kwiver::vital::algo::estimate_essential_matrix,
        estimate,
        feat1,
        feat2,
        matches,
        cal,
        inliers,
        inlier_scale
      );
    }

    kwiver::vital::essential_matrix_sptr
      estimate(const std::vector<kwiver::vital::vector_2d>& pts1,
               const std::vector<kwiver::vital::vector_2d>& pts2,
               const kwiver::vital::camera_intrinsics_sptr cal,
               std::vector<bool>& inliers,
               double inlier_scale)  const override
    {
      VITAL_PYBIND11_OVERLOAD_PURE(
        kwiver::vital::essential_matrix_sptr,
        kwiver::vital::algo::estimate_essential_matrix,
        estimate,
        pts1,
        pts2,
        cal,
        inliers,
        inlier_scale
      );
    }

    kwiver::vital::essential_matrix_sptr
      estimate(const std::vector<kwiver::vital::vector_2d>& pts1,
               const std::vector<kwiver::vital::vector_2d>& pts2,
               const kwiver::vital::camera_intrinsics_sptr cal1,
               const kwiver::vital::camera_intrinsics_sptr cal2,
               std::vector<bool>& inliers,
               double inlier_scale)  const override
    {
      VITAL_PYBIND11_OVERLOAD_PURE(
        kwiver::vital::essential_matrix_sptr,
        kwiver::vital::algo::estimate_essential_matrix,
        estimate,
        pts1,
        pts2,
        cal1,
        cal2,
        inliers,
        inlier_scale
      );
    }
};
}
}
}

#endif
