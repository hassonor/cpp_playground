### Process Memory Layout

A process can be laid out in memory in any way the host OS chooses, but nearly all contemporary(עכשוי) systems observe
a few
common conventions. In general, a process is organized into the following major areas:

* _Program code_-This section contains executable program instructions that can be interpreted by the processor and
  acted on. Program code includes compiled code for the running program and additional code located in shared libraries
  the program uses. Shared libraries aren't usually mapped contiguously with the main program code.
* _Program data_-This section is used to store program variables that aren't local to functions. It includes both global
  and static variables. The data section usually contains a dynamic memory region, called the "program heap", for
  storing dynamically allocated variables.
* _Program stack_-The stack is used for dynamic storage for currently executing functions, and it keeps track of the
  call chain of functions as they execute.

### Stack Overflows

___
**Stack overflows** are buffer overflows in which the target buffer is located on the runtime program stack. They are
the most well understood and, historically, the most straightforward type of buffer overflow to exploit. This section
covers the basics of the runtime program stack and then shows how attackers exploit stack-based buffer overflows.

#### The Stack ADT

From a general computer science perspective, a stack is an abstract data type (ADT) used for the ordered storage and
retrieval (שליפה) of a series of data elements. Users of a stack data structure typically have two operations available
for manipulating the stack:

* `push()` - The push operation adds an element to the top of the stack.
* `pop()`- A pop operation removes and returns the top element from the stack.
  A stack is a last-in, first-out (LIFO) data structure.

#### The Runtime Stack

Each process has a **runtime stack**, which is also referred to as "the program stack", "the call stack", or just "the
stack". The runtime stack provides the underpinning necessary for the functions used in every structured programming
language. Functions can be called in arbitrary order, and they can be recursive and mutually recursive. The runtime
stack supports this functionality with **activation records**, which record the chain of calls from function to function
so that they can be followed back when functions return. And activation record also includes data that needs to be
allocated each time a function is called, such as local variables, saved machine state, and function parameters.
Because runtime stacks are an integral part of how programs function,they are implemented with CPU assistance instead of
as a pure software abstraction. The processor usually has a special register that points to the top of the stack, which
is modified by using `push()` and `pop()` machine instructions. On Intel x86 CPUs, this register is called **ESP** (ESP
stands for "extended stack pointer").
On most modern CPUs, the stack grows downward(כלפי מטה). This means the stack starts at a high address in virtual memory
and grows toward a lower address. A push operation subtracts(מפחית) from the stack pointer so that the stack pointer
moves
toward the lower and process memory. Correspondingly(באופן דומה), the pop operation adds to the stack pointer, moving it
back toward the top of memory.
Every time a function is called, the program creates a new stack frame, which is simply a reserved block of contiguous
memory that a function uses for storing local variables and internal state information. This block of memory is reserved
for exclusive use by the function until it returns, at which time it's removed from the stack. To understand this
process, consider the following program snippet:

```c
int function_B(int a, int b)
{
    int x,y;
    
    x = a * a;
    y = b * b;
    
    return (x+y);
}

int function_A(int p, int q)
{
    int c;
    c = p * q * function_B(p,q);
    
    return c;
}

int main(int argc, char **argv, char **envp)
{
    int ret;
    ret = function _A(1,2);
    return ret;
}
```

When `function_A()` is entered, a stack frame is allocated and places on the top of the stack.
When `function_B()` is finished, it returns back into `function_A()`. The `function_B()` stack frame is popped off the
top of the stack.

Each function manages its own stack frame, which is sized depending on how many local variables are present and the size
of each variable. Local variables need to be accessed directly as the function requires them, which would be inefficient
just using push and pop instructions. Therefore, many programs make use of another register, called the "frame pointer"
or "base pointer". On Intel x86 CPUs, this register is called **EBP** (EBP stands for "extended base pointer"). This
register points to the beginning of the function's stack frame. Each variable in the given frame can be accessed by
referencing a memory location that is a fixed offset from the base pointer. The use of the base pointer is optional, ant
it sometimes omitted, but you can assume that it's present for the purposes of this discussion.
A crucial detail that was glossed(שהועלם) over earlier is the internal state information recorded in each stack frame.
The state information stored on the stack varies among processor architectures, but usually it includes the previous
function's frame pointer and a return adders.
This return address value is saved so that when the currently running function returns, the CPU knows where execution
should continue.
Of course, the frame pointer must also be restored so that local variable accesses remain consistent after a function
has called a sub-function that allocates its own stack frame.

The stack pointer must also be restored to its previous state, but this task isn't performed implicitly; the called
function must reset the stack pointer to the appropriate location before it returns. This is necessary because the saved
frame pointer and return address are restored from the top of the stack. The frame pointer is restored by using a `pop`
instruction, which uses the stack pointer implicitly; the `ret` instruction used to return from a function uses `ESP`
implicitly to retrieve the return address. Each functions that allocates its own stack frame, therefore, needs to save
its own frame pointer.

Consider the simple case of writing over a local variable. The danger with writing over a local variable is that you can
arbitrarily change the variable's values in a manner the application didn't intend. This state change can often have
undesirable consequences.

#### Off-by-One Length Miscalculation

```c
int authenticate(char *username, char *password)
{
    int authenticated;
    char buffer[1024];
    
    authenticated = verify_password(username, password);
    
    if(authenticated == 0){
        sprint(buffer, "password is incorrect for user %s\n",username);
        log("%s", buffer);
    }
    
    return authenticated;
}
```

Assume that the authenticated variable is located at the top of the stack frame, placing it at a higher memory location
than the buffer variable.
The `authenticate()` function has a buffer overflow. Specifically, the `sprintf()` function doesn't limit the amount of
data it writes to the output buffer. Therefore, if the `username` string is around 1024 bytes, data is written past the
end of the buffer variable and into the `authenticated` variable. (Remember that `authenticated()` is at the top of the
stack frame).

The `authenticated` variable is simple state variable, indicating whether the user was able to successfully log on. A
value of zero indicated that authentication failed; a nonzero value indicated success. By overflowing the `buffer`
variable, an attacker can overwrite the `authenticated` variable, thus making it nonzero. Therefore, the called
incorrectly treats the attacker as successfully authenticated!. Overwriting adjacent local variables is a useful
technique, but it's no generally applicable.
Overwriting adjacent local variables is a useful technique, but it's not generally applicable. The technique depends on
what variables are available to overwrite, how the compiler orders the variables in memory, and what the program does
with them after the overflow happens. A more general technique is to target the saved state information in every stack
frame-namely, the saved frame pointer and return address. Of these two variables, the return address is most immediately
useful to attackers. If a buffer overflow can overwrite the saved return address, the application cen be redirected to
an arbitrary point after the currently executing function returns.

Essentially, the attacker chooses an address in the program where some useful code resides and overwrites the return
address with this new address. The exact location depends on what the attacker wants to achieve, but there are two basic
options:

* Execution can be redirected to the code section of the application being run or to some code in a shared that does
  something useful-for example, the `system()` function in UNIX libc, which runs commands via the shell.
* Execution can be redirected to an area of memory containing data the attacker controls, such as a global variable, a
  stack location, or a static buffer. In this situation, the attacker fills the targeted return location with a small
  stub of position-independent code to do something useful, such as connection back to the attacker and spawning a shell
  on the connected socket. These small code stubs are commonly refereed to as **shellcode**.

### SEH Attacks

Windows systems can be vulnerable to a slight variation on the traditional stack overflow attacks; this variation is
knows as "smashing the structured exception handlers". Windows provides **structured exception handling (SEH)** so that
programs can register a handler to act on errors in a consistent manner. When a thread causes an exception to be thrown,
the thread has a chance to catch that exception and recover. Each time a function registers an exception handler, it's
placed at the top of a chain of currently registered exception handlers. When an exception is thrown, this chain is
traversed from the top until the correct handler type is found for the thrown exception. If no appropriate exception
handler is found, the exception is passed to an "unhandled exception filter", which generally terminates the process.

SEH provides a convenient(נוח) method for exploiting stack overflows on a Windows system because the exception handler
registration structures are located on the stack. Each structure has the address of a handler routine and a pointer to
its parent handlers.

When an exception occurs, these records are traversed from the most recently installed handler back to the first one. At
each stage, the handler is executed to determine whether it's appropriate for the currently thrown exception.
Therefore, if an attacker can trigger a stack overflow followed by any sort of exception, these exception registration
structures are examined, and the exception handler address in each structure is called until an appropriate one is
found.
Because they are structures on the attacker-corrupted stack, the application jumps to an address of the attacker's
choosing. When it's possible to overflow a buffer by a fairly large amount, the attacker can copy over the entire stack,
resulting in an exception when the stack base is overwritten. The application then uses the corrupted SEH information on
the stack and jumps to an arbitrary address.

### Of-by-One Errors

Memory corruption is often caused by calculating the length of an array incorrectly. Among the most common mistakes are
**off-by-one errors**, in which a length calculation is incorrect by one array element. This error is typically caused
by failing to account for a terminator element or misunderstanding the way array indexing works.

```c
void process_string(char *src)
{
    char dest[32];
    for ( i = 0; src[i] && (i <= sizeof(dest)); i++)
        dest[i] = src[i];
...
}
```

The `process_string()` function starts by reading a small number of characters from its argument `src` and storing them
to the stack-based buffer `dest`. This code attempts to prevent a buffer overflow if `src` has more than 32 characters,
but it has a simple problem: It can write one element out of bounds into `dest`. Array indexes begin with 0 and extend
to `sizeof(array) - 1`, so an array with 32 members has valid array indexes from 0 through 31. The preceding code
indexes one element past the end of `dest`, as the condition controlling the loop is `(i <= sizeof(dest))` when it
should be `(i <sizeof(dest))`. If `i` is incremented to a value of 32 in the vulnerable code, it passes the length
check, and the program sets `dest[32]` equal to `src[32]`.
This type of issue surfaces repeatedly in code dealing with C strings. C strings require storage space for each byte of
the string as well as one additional byte for the NUL character used to terminate the string. Often this NUL byte isn't
accounted for correctly, which can lead to subtle off-by -one-errors.

For example:

```c
int get_user(char *user)
{
    char buf[1024];
    
    if(strlen(user) > sizeof(buf))
        die("error: user string too long\n");
    
    strcpy(buf,user);
}
```

This code uses the `strlen()` function to check that there's enough room to copy the username into the buffer.
The `strlen()` function returns the number of characters in a C string, but it doesn't count the NUL terminating
character. So if a string is 1024 characters according to `strlen()`, it actually takes up 1025 bytes of space in
memory. In the `get_user()` function, if the supplied user string is exactly 1024 characters, `strlen()` returns 1024,
sizeof() returns 1024, and the length check passes. Therefore, the `strcpy()` function writes 1024 bytes of string data
plus the trailing NUL character, causing one byte too many to be written into `buf`.
Y

#### Off-by-one ex. (Stack Overflow)

___

```c
void process_string(char* src)
{
    char dest[32];
    for(int i =0; src[i] && (i <= sizeof(dest));i++) // The issue here the "<=" instead "<".
        dest[i] = src[i];
}

```

```c
int get_user(char* user)
{
    char buf[1024];
    
    if (strlen(user) > sizeof(buf)) // still has issue since strlen give the length without the '/0' end of string, so it should be ">="
        die("error: user string too long\n");
    
    strcpy(buf,user);
}
```

#### Heap overflow

___
example 1:

```c
void* p = malloc(10);
memcpy(p,"AAAAAAAAAAAAAAAAAAA", 16);
```

### Defences

___

#### Address Space Layout Randomization

```c
#include <studio.h>
int main()
{
    int junk;
    printf("<main>: 0x%p\n", main);
    printf("<junk>: 0x%p\n", &junk);
    
    return 0;
}
```

#### Data Execution Prevention

```c
int main()
{
    char shellcode[] = {0xc3};
    void(*p)() = (void(*)())&shellcode;
    p(); // System that has DEP will stop it and will throw "Segmentation fault (code dumped)"
    
    return 0;
}
```

### גלישה נומרית

```c
void copy_from_user(const int* data, size_t items)
{
    int* mem = (int*)malloc(items * sizeof(int));
    
    for (size_t i = 0; i < items; i++)
        mem[i] = data[i];
    
    /* do stuff with mem... */
    free(mem);
}
```
