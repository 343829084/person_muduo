#include <examples/protobuf/rpc/sudoku.pb.h>


#include <muduo/base/AsyncLogging.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/protorpc/RpcServer.h>

#include <boost/bind.hpp>
#include <stdio.h>
#include <sys/resource.h>
using namespace muduo;
using namespace muduo::net;

int kRollSize = 500*1000*1000;

muduo::AsyncLogging* g_asyncLog = NULL;

namespace sudoku
{

class SudokuServiceImpl : public SudokuService
{
 public:
  virtual void Solve(::google::protobuf::RpcController* controller,
                       const ::sudoku::SudokuRequest* request,
                       ::sudoku::SudokuResponse* response,
                       ::google::protobuf::Closure* done)
  {
    LOG_INFO << "SudokuServiceImpl::Solve";
    response->set_solved(true);
    response->set_checkerboard("1234567");
    done->Run();
  }
};

}

void asyncOutput(const char* msg, int len)
{
  g_asyncLog->append(msg, len);
}



int main(int argc, char* argv[])
{
  {
    // set max virtual memory to 2GB.
    size_t kOneGB = 1000*1024*1024;
    rlimit rl = { 2*kOneGB, 2*kOneGB };
    setrlimit(RLIMIT_AS, &rl);
  }

  char name[256];
  strncpy(name, argv[0], 256);
  muduo::AsyncLogging log(::basename(name), kRollSize);
  log.start();
  g_asyncLog = &log;
  muduo::Logger::setOutput(asyncOutput);


  LOG_INFO << "pid = " << getpid();
  EventLoop loop;
  InetAddress listenAddr(9981);
  sudoku::SudokuServiceImpl impl;
  RpcServer server(&loop, listenAddr);
  server.registerService(&impl);
  server.start();
  loop.loop();
  google::protobuf::ShutdownProtobufLibrary();
}

