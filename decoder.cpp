#include "decoder.h"

// Function to encode a vector of bytes into an ASCII85 string
std::string encode(std::vector<uint8_t> vectorChars)
{
    size_t length = vectorChars.size(); // Get the size of the input vector
    std::ostringstream finalString;    // Create a string stream to store the encoded result

    // Process the input vector in chunks of 4 bytes
    for (size_t i = 0; i < length; i += 4)
    {
        uint32_t value32 = 0; // Initialize a 32-bit integer to store 4 bytes of data

        // Combine 4 bytes into a single 32-bit integer
        for (size_t j = 0; j < 4; j++)
        {
            if ((i + j) < length)
            {
                // Shift the current value left by 8 bits and add the next byte
                value32 = (value32 << 8) | vectorChars[i + j];
            }
            else
            {
                // If there are fewer than 4 bytes remaining, pad with zeros
                value32 <<= 8;
            }
        }

        // Convert the 32-bit integer into 5 ASCII85 characters
        char output[5]; // Array to store the resulting 5 characters

        for (int k = 4; k >= 0; k--)
        {
            // Calculate the ASCII85 character by taking modulo 85 and adding '!'
            output[k] = char(value32 % 85 + '!');
            value32 /= 85; // Reduce the value for the next character
        }

        // Append the 5 ASCII85 characters to the final result
        finalString.write(output, 5);
    }

    // Return the encoded string
    return finalString.str();
}


std::string decode(std::vector<uint8_t> vectorChar)
{
    size_t lenght = vectorChar.size(); // Get the size of the input vector
    std::ostringstream finalString;    // Create a string stream to store the decoded result
    char input[5];                    // Array to store 5 ASCII85 characters for processing

    // Process the input vector in chunks of 5 characters (ASCII85 encoding uses 5 chars per 4 bytes)
    for (size_t i = 0; i < lenght; i += 5)
    {
        uint32_t value32 = 0; // Initialize a 32-bit integer to store the decoded value
        size_t actualSize = 0; // Track the actual number of characters processed in this chunk

        // Read up to 5 characters from the input vector
        for (size_t j = 0; j < 5 && (i + j) < lenght; j++)
        {
            // Validate that the character is within the valid ASCII85 range ('!' to 'u')
            if (vectorChar[i + j] < '!' || vectorChar[i + j] > 'u')
            {
                throw std::runtime_error("Invalid ASCII85 character");
            }
            input[j] = vectorChar[i + j]; // Store the valid character in the input array
            actualSize++; // Increment the count of processed characters
        }

        // Convert the 5 ASCII85 characters into a 32-bit integer
        for (size_t j = 0; j < actualSize; ++j)
        {
            value32 = value32 * 85 + (input[j] - '!'); // Decode the ASCII85 characters
        }

        // Convert the 32-bit integer back into 4 bytes of binary data
        char output[4]; // Array to store the resulting 4 bytes
        for (int k = 3; k >= 0; k--)
        {
            output[3 - k] = char((value32 >> (k * 8)) & 0xFF); // Extract each byte from the 32-bit value
        }

        // Write the decoded bytes to the final string stream
        // Only write the number of bytes corresponding to the actual characters processed
        finalString.write(output, actualSize - 1);
    }

    // Return the decoded string
    return finalString.str();
}