#include "sunone_aimbot_2/mouse/MediusRuntime.h"
#include <iostream>

int main()
{
    std::cout << "Supported ABI: " << MediusRuntime::supportedAbiLabel() << '\n';
    std::cout << "Supported versions: " << MediusRuntime::supportedVersionLabel() << '\n';
    return MediusRuntime::supportedAbiLabel().empty() ? 1 : 0;
}
