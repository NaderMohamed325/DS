#include <iostream>
#include "Stacked.h"

int main() {
    Status re; // Declare re as a Status, not Status*
    Stack *s = CreateStack(5, &re);

    // Check if the stack creation was successful
    if (re == S_yes) {
        // Push elements onto the stack
        PushElement(s, reinterpret_cast<void *>(5));
        PushElement(s, reinterpret_cast<void *>(5));
        PushElement(s, reinterpret_cast<void *>(5));
        PushElement(s, reinterpret_cast<void *>(5));
        PushElement(s, reinterpret_cast<void *>(5));
        PushElement(s,(void*)6);
        // Destroy the stack when done
        s = DestroyStack(s, &re);
    } else {
        std::cout << "Failed to create the stack." << std::endl;
    }

    return 0;
}
