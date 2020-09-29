#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <sstream>
#include <string>

/// Return hex string from bytes in input string.
std::string hex(const std::string &input) {
  std::stringstream hex_stream;
  hex_stream << std::hex << std::internal << std::setfill('0');
  for (auto &byte : input)
    hex_stream << std::setw(2) << (int)(unsigned char)byte;
  return hex_stream.str();
}

/// Return the SHA-512 (512-bit) hash from input.
std::string sha1(const std::string &input) {
  std::string hash;
  hash.resize(160 / 8);
  SHA1((const unsigned char *)&input[0], input.size(), (unsigned char *)&hash[0]);
  return hash;
}

int main() {
  std::string input = "QwE";
  input = "Saltet til Ola" + input;
  std::cout << "Task1!" << std::endl;
  for (int i = 0; i < 2048; i++) {
    input = hex(sha1(input));
  }
  std::cout << input << std::endl;
}