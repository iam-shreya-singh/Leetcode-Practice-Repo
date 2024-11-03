#include <string> // Include necessary library for using strings
#include <cstring> // Include C-string library for strstr function

class Solution {
public:
    // Function to check if string 's' after rotation can become string 'goal'
    bool rotateString(std::string s, std::string goal) {
        // First check if the sizes of both strings are equal, an essential condition for rotation
        if (s.size() != goal.size()) {
            return false; // If sizes differ, one cannot be a rotation of the other
        }

        // Double the string 's' so that it contains all possible rotations
        std::string doubled_s = s + s;

        // Use the C library function 'strstr' to check if 'goal' is a substring of 'doubled_s'
        // 'strstr' returns a pointer to the first occurrence of 'goal' in 'doubled_s', or a null pointer if 'goal' is not present
        // 'data()' method provides a pointer to the start of the string data
        return strstr(doubled_s.data(), goal.data()) != nullptr;
    }
};
