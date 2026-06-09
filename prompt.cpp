#include "prompt.h"

#include <iostream>
#include <limits>

namespace   // for internal linkage
{
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool validateInput()
    {
        if (!std::cin) {

            if (std::cin.eof()) {
                exit(0);
            }

            std::cin.clear();
            ignoreLine();

            return false;
        }
        
        if (std::cin.peek() != '\n') {  // if extraction succeeded but input buffer still contains invalid characters
            ignoreLine();
            return false;
        }

        return true;
    }
}

int Prompt::promptInt(std::string_view prompt)
{
    while (true) {
        std::cout << prompt;

        int n{};
        std::cin >> n;

        if (validateInput()) {
            return n;
        }

        std::cout << "Invalid input.\n";
    }
}
