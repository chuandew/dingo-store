// Copyright (c) 2023 dingodb.com, Inc. All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Copyright (C) 2019-2023 Zilliz. All rights reserved.

#ifndef DINGODB_SIMD_DISTANCES_REF_H_
#define DINGODB_SIMD_DISTANCES_REF_H_

#include <cstdio>

namespace dingodb {

/// Squared L2 distance between two vectors
float fvec_L2sqr_ref(const float* x, const float* y, size_t d);

/// inner product
float fvec_inner_product_ref(const float* x, const float* y, size_t d);

/// L1 distance
float fvec_L1_ref(const float* x, const float* y, size_t d);

/// infinity distance
float fvec_Linf_ref(const float* x, const float* y, size_t d);

/// squared norm of a vector
float fvec_norm_L2sqr_ref(const float* x, size_t d);

/// compute ny square L2 distance between x and a set of contiguous y vectors
void fvec_L2sqr_ny_ref(float* dis, const float* x, const float* y, size_t d, size_t ny);

/// compute the inner product between nx vectors x and one y
void fvec_inner_products_ny_ref(float* ip, const float* x, const float* y, size_t d, size_t ny);

void fvec_madd_ref(size_t n, const float* a, float bf, const float* b, float* c);

int fvec_madd_and_argmin_ref(size_t n, const float* a, float bf, const float* b, float* c);

}  // namespace dingodb

#endif  // DINGODB_SIMD_DISTANCES_REF_H_ //NOLINT
