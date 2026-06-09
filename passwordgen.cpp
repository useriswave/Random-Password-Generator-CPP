#include "passwordgen.h"

#include <string_view>
#include <random>

namespace
{
    constexpr std::string_view g_COMBINATION { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+.,?/';{}][<>|:" };

    // seeding mersenne twister once
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution range(0, static_cast<int>(g_COMBINATION.size()) - 1);
}

std::string Generator::getRandomPassword(std::size_t size)
{
 
    std::string password{};

    for (size_t i{}; i < size; ++i) {
        password += g_COMBINATION[range(mt)];
    }
    
    return password;
}
