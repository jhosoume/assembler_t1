#include "PreProcessing.hpp"

PreProcessor::PreProcessor(File file)
  : input_file{file}
  {}

void PreProcessor::exec() {
  std::ifstream ifs(input_file.fullname());
  // Testing if file can be oppened
  if (!ifs.is_open()) {
    throw std::runtime_error("[ERR] " + input_file.fullname() + " could not be opened");
  }
  string line;

  while(std::getline(ifs, line)) {
      cout << line << endl;
  }


}
