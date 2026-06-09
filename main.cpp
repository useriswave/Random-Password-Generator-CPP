#include "prompt.h"
#include "passwordgen.h"

#include <iostream>

int main()
{
    while (true) {
        int passwordSize { Prompt::promptInt("Enter a password size: ") };
    
        if (passwordSize <= 0) {
            std::cout << "Please enter a valid password size.\n";
        } else {
            std::string password { Generator::getRandomPassword(static_cast<std::size_t>(passwordSize)) };
            std::cout << "Your generated password is: " << password << "\n";

            break;
        }
    }
 
    return 0;
}
