#pragma once
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;
class Tiempo {
public:
  void begin() {
    begin_pt = system_clock::now();
  }
  void end() {
    end_pt = system_clock::now();
  }
  double time() const {
    return duration<double>(end_pt - begin_pt).count();
  }
private:
  std::chrono::time_point<std::chrono::system_clock> begin_pt, end_pt;
};


