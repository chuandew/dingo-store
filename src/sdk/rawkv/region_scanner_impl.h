
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

#ifndef DINGODB_SDK_REGON_SCANNER_IMPL_H_
#define DINGODB_SDK_REGON_SCANNER_IMPL_H_

#include <cstdint>
#include <memory>
#include <vector>

#include "sdk/client.h"
#include "sdk/client_stub.h"
#include "sdk/region_scanner.h"
#include "sdk/store/store_rpc.h"

namespace dingodb {
namespace sdk {
class RegionScannerFactoryImpl;
class TestBase;

class RegionScannerImpl : public RegionScanner {
 public:
  explicit RegionScannerImpl(const ClientStub& stub, std::shared_ptr<Region> region);

  explicit RegionScannerImpl(const ClientStub& stub, std::shared_ptr<Region> region, std::string start_key,
                             std::string end_key);

  ~RegionScannerImpl() override;

  Status Open() override;

  void Close() override;

  Status NextBatch(std::vector<KVPair>& kvs) override;

  bool HasMore() const override;

  Status SetBatchSize(int64_t size) override;

  int64_t GetBatchSize() const override { return batch_size_; }

  bool TEST_IsOpen() {  // NOLINT
    return opened_;
  }

 private:
  void PrepareScanBegionRpc(KvScanBeginRpc& rpc);

  void PrepareScanContinueRpc(KvScanContinueRpc& rpc);

  void PrepareScanReleaseRpc(KvScanReleaseRpc& rpc);

  std::string start_key_;
  std::string end_key_;
  int64_t batch_size_;
  bool opened_;
  std::string scan_id_;
  bool has_more_;
};

class RegionScannerFactoryImpl final : public RegionScannerFactory {
 public:
  RegionScannerFactoryImpl();

  ~RegionScannerFactoryImpl() override;

  Status NewRegionScanner(const ClientStub& stub, std::shared_ptr<Region> region,
                          std::unique_ptr<RegionScanner>& scanner) override;
};

}  // namespace sdk
}  // namespace dingodb
#endif  // DINGODB_SDK_REGON_SCANNER_H_