#pragma once
#include <chrono>
#include <string>
namespace NBenchmark { class CTimer { public: explicit CTimer(std::string label="Duration"); ~CTimer(); private: std::chrono::steady_clock::time_point start; std::string label; }; }
