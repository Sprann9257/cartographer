/*
 * Copyright 2017 The Cartographer Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CARTOGRAPHER_CLOUD_INTERNAL_HANDLERS_RECEIVE_LOCAL_SLAM_RESULTS_HANDLER_H
#define CARTOGRAPHER_CLOUD_INTERNAL_HANDLERS_RECEIVE_LOCAL_SLAM_RESULTS_HANDLER_H

#include <memory>

#include "cartographer/cloud/internal/framework/rpc_handler.h"
#include "cartographer/cloud/internal/map_builder_context_interface.h"
#include "cartographer/cloud/proto/map_builder_service.pb.h"

namespace cartographer {
namespace cloud {
namespace handlers {

class ReceiveLocalSlamResultsHandler
    : public framework::RpcHandler<
          proto::ReceiveLocalSlamResultsRequest,
          framework::Stream<proto::ReceiveLocalSlamResultsResponse>> {
 public:
  std::string method_name() const override {
    return "/cartographer.cloud.proto.MapBuilderService/"
           "ReceiveLocalSlamResults";
  }
  void OnRequest(const proto::ReceiveLocalSlamResultsRequest& request) override;
  void OnFinish() override;

 private:
  std::unique_ptr<MapBuilderContextInterface::SubscriptionId> subscription_id_;
};

}  // namespace handlers
}  // namespace cloud
}  // namespace cartographer

#endif  // CARTOGRAPHER_CLOUD_INTERNAL_HANDLERS_RECEIVE_LOCAL_SLAM_RESULTS_HANDLER_H
