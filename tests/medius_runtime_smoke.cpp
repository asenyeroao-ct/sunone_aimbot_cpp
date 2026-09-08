#include "sunone_aimbot_2/mouse/MediusRuntime.h"

#include <iostream>

int main()
{
    if (MediusRuntime::supportedAbiLabel() != "6")
        return 1;
    if (MediusRuntime::controlBaudRate() != 4000000u)
        return 2;
    if (MediusRuntime::customBaudSupported())
        return 3;

    MediusRuntime& runtime = MediusRuntime::instance();
    if (!runtime.setPreferredPort("COM7") || runtime.preferredPort() != "COM7")
        return 4;
    if (!runtime.setPreferredPort("\\\\.\\COM12") || runtime.preferredPort() != "COM12")
        return 5;
    if (runtime.setPreferredPort("INVALID"))
        return 6;
    if (runtime.setControlBaudRate(115200u))
        return 7;
    if (!runtime.setControlBaudRate(4000000u))
        return 8;
    if (!runtime.setPreferredPort("AUTO") || runtime.preferredPort() != "AUTO")
        return 9;

    std::cout << "Supported ABI: " << MediusRuntime::supportedAbiLabel() << '\n';
    std::cout << "Supported versions: " << MediusRuntime::supportedVersionLabel() << '\n';
    std::cout << "Control baud: " << MediusRuntime::controlBaudRate() << '\n';
    std::cout << "Port policy: PASS\n";
    return 0;
}
