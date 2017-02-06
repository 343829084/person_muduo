cc_binary (
  name = "fastcgi",
  srcs = [
    "fastcgi.cc",
    "fastcgi_test.cc",
  ],
  deps = [
    "//muduo/base:libbase",
    "//muduo/net:libnet",
    "//thirdparty/boost:boost_date_time",
    '//thirdparty/boost:boost_locale',
    "//thirdparty/boost:boost_system",
    "//thirdparty/boost:boost_thread",
    "#pthread",
  ])

