#### Processes and Threads

```cpp
#include <thread>

void mythread(){
    // do some important stuff
}

int main(){
    std::thread t1(mytread); // t1 will run immediately
    
    // do other important stuff in parallel
    
    t1.join(); // wait for mythread to finish
    
    return 0;
}
```
```cpp
#include <iostream>
#include <thread>

int g_value = 0;
void challenge(){
    for (int i = 0; i < 10; i++)
        g_value++;
}

int main(int argc, char** argv){
    std::thread t1(challenge);
    std::trhead t2(challenge);
    t1.join();
    t2.join();
    std::cout << g_value <<std::endl; // Due to parallel execution the result will be between 10 and 20.
    return 0;
}

```

### Synchronization
