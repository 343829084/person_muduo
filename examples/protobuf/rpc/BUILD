proto_library (
  name = "sudoku_proto",
  srcs = [
      "sudoku.proto",
  ],
  )



cc_binary (
  name = "server",
  srcs = [
      "server.cc",
  ],
  deps = [
    "//muduo/base:libbase",
    "//muduo/net:libnet",
    "//examples/protobuf/rpc:sudoku_proto",
    "//thirdparty/boost:boost_date_time",
    '//thirdparty/boost:boost_locale',
    "//thirdparty/boost:boost_system",
    "//thirdparty/boost:boost_thread",
    "#pthread",
  ])


cc_binary (
  name = "client",
  srcs = [
      "client.cc",
  ],
  deps = [
    "//muduo/base:libbase",
    "//muduo/net:libnet",
      "//examples/protobuf/rpc:sudoku_proto",
    "//thirdparty/boost:boost_date_time",
    '//thirdparty/boost:boost_locale',
    "//thirdparty/boost:boost_system",
    "//thirdparty/boost:boost_thread",
    "#pthread",
  ])

