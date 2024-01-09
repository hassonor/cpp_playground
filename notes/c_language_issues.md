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