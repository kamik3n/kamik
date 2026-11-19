#include "Timer.h"
#include <iostream>
#include <utility>
namespace NBenchmark { CTimer::CTimer(std::string l):start(std::chrono::steady_clock::now()),label(std::move(l)){} CTimer::~CTimer(){auto d=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count();std::cout<<label<<": "<<d<<" microseconds\n";} }
