#include "sibyl.hpp"

#include "spdlog/spdlog.h"

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

    void log()
    {
        spdlog::info("Logging from Sibyl library.");
    }
} // namespace sibyl