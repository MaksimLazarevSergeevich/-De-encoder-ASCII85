import subprocess  # Allows running external programs
import base64      # Used to generate reference results using Python's built-in Ascii85 functions

# Path to compiled C++ executable
BINARY = './ascii85'

# Helper function to run the C++ program with given mode (-e or -d) and input bytes
def run_program(mode, input_bytes):
    result = subprocess.run(
        [BINARY, mode],           # Example: ./ascii85 -e or ./ascii85 -d
        input=input_bytes,        # Data sent to the program's standard input (stdin)
        stdout=subprocess.PIPE,   # Capture standard output (stdout)
        stderr=subprocess.PIPE    # Capture standard error (stderr)
    )
    return result  # Return the result object containing output, errors, and exit code

# Test: Check if the encoder correctly encodes "Hello" using Ascii85
def test_encoder_hello():
    input_data = b'Hello'  # Original input bytes
    # Expected output using Python's Ascii85 encoder (with padding enabled to match C++ behavior)
    expected = base64.a85encode(input_data, pad=True).decode()

    result = run_program('-e', input_data)  # Run the encoder

    # Ensure the program exited successfully
    assert result.returncode == 0
    # Check if the encoded output matches the expected value
    assert result.stdout.decode().strip() == expected

# Test: Check if the decoder correctly decodes Ascii85-encoded "Hello"
def test_decoder_hello():
    original = b'Hello'  # Original byte string
    # Encode using Python to get the expected Ascii85 input for the decoder
    encoded = base64.a85encode(original, pad=True)

    result = run_program('-d', encoded)  # Run the decoder

    # Ensure successful exit
    assert result.returncode == 0
    # Compare the output to the original input
    assert result.stdout.strip() == original

# Test: Decoder should fail on invalid Ascii85 input
def test_decoder_invalid_input():
    bad_data = b'!invalid!'  # Intentionally malformed input

    result = run_program('-d', bad_data)  # Run decoder with invalid data

    # The decoder should return an error (non-zero exit code)
    assert result.returncode != 0

# Test: Encoder should handle empty input correctly
def test_encoder_empty():
    result = run_program('-e', b'')  # Empty input
    expected = base64.a85encode(b'').decode()  # Expected empty Ascii85 output

    assert result.returncode == 0
    assert result.stdout.decode().strip() == expected

# Test: Decoder should also handle empty input without errors
def test_decoder_empty():
    # Encode empty input using Python
    result = run_program('-d', base64.a85encode(b''))

    assert result.returncode == 0
    # The result should also be empty
    assert result.stdout.strip() == b''