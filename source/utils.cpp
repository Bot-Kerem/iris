#include "iris/utils.hpp"

#include <fstream>
#include <stdexcept>
#include <vector>

std::string open_file(const std::string_view path) {
  std::ifstream file(path.data(), std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file: " + std::string(path));
  }
  // Get the size of the file
  file.seekg(0, std::ios::end);
  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  // Read the entire file into a vector
  std::vector<char> buffer(size);
  if (!file.read(buffer.data(), size)) {
    throw std::runtime_error("Error reading file: " + std::string(path));
  }
  file.close();
  return std::string(buffer.begin(), buffer.end());
}
