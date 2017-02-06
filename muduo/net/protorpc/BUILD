proto_library (
  name = "rpcclient_proto",
  srcs = [
    "rpc.proto",    
  ],
)






proto_library (
  name = "rpcservice_proto",
  srcs = [
    "rpcservice.proto",    
  ],
  deps = [
    "//muduo/net/protorpc:rpcclient_proto",
  ],
)







cc_library (
  name = "rpc_proto",
  srcs = [
    "RpcChannel.cc",
      "RpcCodec.cc",
      "RpcServer.cc",
  ],
  deps = [
    "//thirdparty/boost:boost_thread",
    "//muduo/net/proto:rpcservice_proto",
  ],
)



