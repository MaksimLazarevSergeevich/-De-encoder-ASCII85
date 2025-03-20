#include "decoder.h"

// Main function to handle encoding or decoding based on command-line arguments
int main(int argc, char* argv[])
{
    bool encd = true; // Flag to determine whether to encode (true) or decode (false)

    // Check command-line arguments to determine the mode
    if (argc > 1 && std::string(argv[1]) == "-d")
    {
        encd = false; // If the "-d" flag is provided, set the mode to decode
    }
    else if (argc > 1 && std::string(argv[1]) == "-e")
    {
        encd = true;
    }
    

    // Read input from standard input (stdin)
    std::string input;
    std::getline(std::cin, input);

    // Convert the input string into a vector of uint8_t (bytes)
    std::vector<uint8_t> charInput;
    for (uint8_t ch : input)
    {
        charInput.push_back(ch); // Add each character to the vector
    }

    try
    {
        // Perform encoding or decoding based on the mode
        if (encd)
        {
            // Encode the input and print the result
            std::cout << encode(charInput) << std::endl;
        }
        else
        {
            // Decode the input and print the result
            std::cout << decode(charInput) << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        // Handle and display any errors that occur during encoding or decoding
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate an error
    }

    return 0; // Return 0 to indicate successful execution
}