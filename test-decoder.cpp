#include <gtest/gtest.h>
#include "decoder.h"

TEST(decoder, firstTest)
{
    std::string input = "Hello world!";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}

TEST(decoder, secondTest)
{
    std::string input = "";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}

TEST(decoder, thirdTest)
{
    std::string input = "efiwheufh  alhsfhaiuh  sh lfuih []ee";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}

TEST(decoder, fourthTest)
{
    std::string input = "der der ijijis kmkmmse mpsemfp 909238824 wejfiuffffff";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}

TEST(decoder, fifthTest)
{
    std::string input = "O, <> GREATERGUYES  .//././,,';;[po=-098345123`zzzxa]";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}

TEST(decoder, sixthTest)
{
    std::string input = "**///***/*+++=+-_)(*7&^^6%$#@!`?:)";
   // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }
    std::string encodeInput = encode(charInput);

    charInput.clear();

    for (uint8_t ch : encodeInput)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    std::string decodeInput = decode(charInput);

    ASSERT_EQ(decodeInput, input);
}