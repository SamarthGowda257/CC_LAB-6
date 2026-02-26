#include <iostream>
#include <cstdlib>

int main() {
    const char* hostname = getenv("HOSTNAME");
    std::cout << "Hello from container: " << (hostname ? hostname : "unknown") << std::endl;
    return 0;
}
