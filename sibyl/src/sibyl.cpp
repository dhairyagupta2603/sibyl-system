#include "sibyl.hpp"

#include <iostream>
#include <spdlog/spdlog.h>
#include <libevdev/libevdev.h>

#include <fcntl.h>
#include <unistd.h>

namespace sibyl
{
    int add(int a, int b)
    {
        return a + b;
    }

    int subtract(int a, int b)
    {
        return a - b;
    }

    int check()
    {
        const char *device_path = "/dev/input/event0"; // Replace with a valid device path
        int fd = open(device_path, O_RDONLY | O_NONBLOCK);
        if (fd < 0)
        {
            std::cerr << "Error: Unable to open device " << device_path << std::endl;
            return 1;
        }

        struct libevdev *dev = nullptr;
        if (libevdev_new_from_fd(fd, &dev) < 0)
        {
            std::cerr << "Error: Failed to initialize libevdev" << std::endl;
            close(fd);
            return 1;
        }

        std::cout << "Device initialized successfully!" << std::endl;
        std::cout << "Device name: " << libevdev_get_name(dev) << std::endl;

        libevdev_free(dev);
        close(fd);
        return 0;
    }

    void log()
    {
        spdlog::info("Logging from Sibyl library.");
        int res = check();
        spdlog::info(res);
        
    }
} // namespace sibyl