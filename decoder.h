#ifndef DECODER_H
#define DECODER_H
#include <vector>
#include <iostream>
#include <cstdint>
#include <sstream>
#include <stdexcept>

std::string encode(std::vector<uint8_t>); // encode

std::string decode(std::vector<uint8_t>); // decode

#endif