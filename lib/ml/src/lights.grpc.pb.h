// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: lights.proto
#ifndef GRPC_lights_2eproto__INCLUDED
#define GRPC_lights_2eproto__INCLUDED

#include "lights.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

class Lights final {
 public:
  static constexpr char const* service_full_name() {
    return "Lights";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::Action, ::Detection>> Connect(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::Action, ::Detection>>(ConnectRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>> AsyncConnect(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>>(AsyncConnectRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>> PrepareAsyncConnect(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>>(PrepareAsyncConnectRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Connect(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::Action,::Detection>* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::Action, ::Detection>* ConnectRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>* AsyncConnectRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::Action, ::Detection>* PrepareAsyncConnectRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::Action, ::Detection>> Connect(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::Action, ::Detection>>(ConnectRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>> AsyncConnect(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>>(AsyncConnectRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>> PrepareAsyncConnect(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>>(PrepareAsyncConnectRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Connect(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::Action,::Detection>* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReaderWriter< ::Action, ::Detection>* ConnectRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>* AsyncConnectRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::Action, ::Detection>* PrepareAsyncConnectRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Connect_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_Connect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Connect() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Connect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestConnect(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::Detection, ::Action>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Connect<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Connect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Connect() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackBidiHandler< ::Action, ::Detection>(
          [this] { return this->Connect(); }));
    }
    ~ExperimentalWithCallbackMethod_Connect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::experimental::ServerBidiReactor< ::Action, ::Detection>* Connect() {
      return new ::grpc::internal::UnimplementedBidiReactor<
        ::Action, ::Detection>;}
  };
  typedef ExperimentalWithCallbackMethod_Connect<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Connect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Connect() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Connect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Connect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Connect() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Connect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestConnect(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Connect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Connect() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this] { return this->Connect(); }));
    }
    ~ExperimentalWithRawCallbackMethod_Connect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Connect(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Detection, ::Action>* stream)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::experimental::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* Connect() {
      return new ::grpc::internal::UnimplementedBidiReactor<
        ::grpc::ByteBuffer, ::grpc::ByteBuffer>;}
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};


#endif  // GRPC_lights_2eproto__INCLUDED
