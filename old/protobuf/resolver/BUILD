cc_binary (
  name = "client",
  srcs = [
    "client.cc",
  ],
  deps = [
    "//muduo/proto:resolver_proto",
    "//muduo/base:libbase",
    "//muduo/net:libnet",
    "//thirdparty/boost:boost_date_time",
    '//thirdparty/boost:boost_locale',
    "//thirdparty/boost:boost_system",
    "//thirdparty/boost:boost_thread",
    "#pthread",
  ])

cc_binary(
    name = 'server',
    srcs = [
    'server.cc',
    ],
    deps = [
    "//muduo/proto:resolver_proto",
        "//examples/cdns:cdns",
    "//muduo/base:libbase",
    "//muduo/net:libnet",
    '//thirdparty/boost:boost_date_time',
     '//thirdparty/boost:boost_locale',
    "//thirdparty/boost:boost_system",
    "//thirdparty/boost:boost_thread",
    '#pthread',
    "#c-ares-dev",
    ]
    )
