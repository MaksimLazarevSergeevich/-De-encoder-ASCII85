## (Де)кодер ASCII85
## Author
Лазарев Максим Сергеевич 24.Б82-мм.
## Contacts
st128707@student.spbu.ru
## Description
ASCII85 Decoder
This project is a C++ implementation of an ASCII85 decoder. The decoder converts ASCII85 encoded data back to the original bytes.
# Prerequisites
sudo apt install build-essential

# Build
Demo application
make

# Run
Demo application
./ascii85        === encode
./ascii85 -e     === encode
./ascii85 -d     === decode

# Examples
make

./ascii85
#### input
Hello, World!
#### output
87cURD_*#4DfTZ)+TMKB

./ascii85 -d
#### input
87cURD_*#4DfTZ)+TMKB
#### output
Hello, World!

#### input
echo -n "Hello" | ./ascii85 -e
#### output
87cURDZBb;

#### input
echo -n "87cURDZBb;" | ./ascii85 -d
#### output
Hello
