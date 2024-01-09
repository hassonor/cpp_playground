#### Byte Order

____
There are two conventions for ordering bytes in modern architectures **big endian** and **little endian**. These
convention apply to data types larger than 1 byte, such as a short int or an int. In the big-endian architecture, the
bytes are located in memory starting with the most significant byte and ending with the least significant byte.
Little-endian architectures, however, start with the least significant byte and end with the most significant. For
example, you have 4-byte integer with the decimal value 12345. In binary, it's `11000000111001`.

```text
It's represented in memory as the following:

Big-endian machine:
___________________
Address 500: 00000000
Address 501: 00000000
Address 502: 00110000
Address 503: 00111001

Little-endian machine:
____________________
Address 500: 00111001
Address 501: 00110000
Address 502: 00000000
Address 503: 00000000
``` 

