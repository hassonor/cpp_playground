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

#### Integer Overflow Example

```c
u_char *make_table(unsigned int width, unsigned in height, u_char *init_row)
{
    unsigned int n;
    int i;
    u_char *buf;
    
    n = width * height;
    
    buf (char*)malloc(n);
    if(!buf)
        return (NULL);

    for(i=0; i < height; i++)
        memcpy(&buf[i*width], init_row, width);
    
    return buf;
}
```

#### Challenge-Response Integer Overflow Example in OpenSSH 3.1

```c
u_int nresp;
...
nresp = packet_get_int();
if (nresp > 0){
    response = xmalloc(nresp * sizeof(char*));
    for(i = 0; i < nresp; i++)
        response[i] = packet_get_string(NULL);
}
packet_check_eom();
```

The `nresp` unsigned integer is user controlled, and its purpose is to tell the server how many responses to expect.
It's used to allocate the `response[]` array and fill it with network data. During the allocation of the `response[]`
array in the call to `xmalloc()`, `nresp` is multiplied by `sizeof(char*)`, which typically 4 bytes. If users
specify `nresp` value that's large enough, a numeric overflow could occur, and the result of the multiplication could
end up being a small number. For example if `nresp` has a value of `0x40000020`, the result of the multiplication with 4
is `0x80`. Therefore, `0x80` bytes are allocated, but the following for loop attempts to retrieve exploitable
vulnerability.

#### Unsigned Integer Underflow Example

```c
struct header {
    unsigned int length;
    unsigned int message_type;
};

char *read_packet(int sockfd)
{
    int n;
    unsigned int length;
    struct header hdr;
    static char buffer[1024];
    
    if(full_read(sockfd, (void*)&hdr, sizeof(hdr))<=0){
        error("full_read: %m");
        return NULL;
    }
    
    length = ntohl(hdr.length);
    
    if(length > (1024 + sizeof(struct header) - 1)) {
        error("not enough room in buffer\n");
        return NULL;
    }
    
    if(full_read(sockfd, buffer, length - sizeof(struct header))<=0){
        error("read: %m");
        return NULL;
    }
    
    buffer[sizeof(buffer)-1] = '\0';
    
    return strdup(buffer);
}
```

The vulnerability is that if users supply a length less than `sizeof(struct header)`, the subtraction
of`(length - sizeof(struct header))` causes an integer underflow and ends up passing a very large size parameter
to `full_read()`. This error could result in a buffer overflow because at that point, `read()` would essentially copy
data into the buffer until the connection is closed, which would allow attackers to take control of the process.

#### Signed Integer Vulnerability Example

```c
char *read_data(int sockfd)
{
    char *buf;
    int length = network_get_int(sockfd);
    
    if(!(buf = (char*)malloc(MAXCHARS)))
        die("malloc: %m");
    
    if(length < 0 || length + 1 >= MAXCHARS){
        free(buf);
        die("bad length: %d", value);
    }
    
    if(read(sockfd, buf, length) <= 0){
        free(buf);
        die("read: %m");
    }
    
    buf[value] = '\0';
    return buf;
}
```

This example reads an integer from the network and performs some sanity checks on it. First, the length is checked to
ensure that it's greater than or equals to zero and, therefore, positive. Then the length is checked to ensure that it's
less than `MAXCHARS`. However, in the second part of the length check, 1 is added to the length. This opens an attack
vector: A value of `0x7FFFFFFF` passes the first check (because it's greater than 0) and passes the second length
check (as `0x7FFFFFFFF` + 1 is `0x80000000`, which is negative value). `read()` would then be called with an effectively
unbounded length argument, leading to a potential buffer overflow situation. This kind of mistake is easy to make when
dealing with signed integers, and it can be equally challenging to spot.

### Types Conversions

___

#### Integer Type Conversion

Here are some practical rules of thumb for integer type conversions:

* When you convert from narrower signed type to a wider unsigned type, the compiler emits assembly to do sign extension,
  and the value of the object might change.
* When you convert from a narrower signed type to a wider signed type, the compiler emits assembly to do sign extension,
  and the value of the object is preserved.
* When you convert from a narrower unsigned type to a wider type, the compiler emits assembly to do zero extension, and
  the value of the object is preserved.
* When you convert from a wider type to a narrower type, the compiler emits assembly to do truncation, and the value of
  the object might change.
* When you convert between signed and unsigned types of the same width, the compiler effectively does nothing, the bit
  pattern stays the same, and the value of the object might change.
