#pragma once
#include <chrono>
#include <fstream>

class Tiempo {
public:
  void begin();
  void end();
  double time() const;
private:
  std::chrono::time_point<std::chrono::system_clock> begin_pt, end_pt;
};

using namespace std;
using namespace std::chrono;

void Tiempo::begin() {
  begin_pt = system_clock::now();
}

void Tiempo::end() {
  end_pt = system_clock::now();
}

double Tiempo::time() const {
  return duration<double>(end_pt - begin_pt).count();
}
