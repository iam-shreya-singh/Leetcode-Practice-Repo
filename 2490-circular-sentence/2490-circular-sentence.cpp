#include <string> // Include string library to use the string class
using namespace std;

class Solution {
public:
    // Function to check if the sentence is circular.
    // A circular sentence must start and end with the same character, and after every
    // space character, the next character must be the same as the last character before the space.
    bool isCircularSentence(string sentence) {
        int length = sentence.size(); // Get the size of the string
      
        // Check if the first and last character of the sentence is not the same
        if (sentence[0] != sentence[length - 1]) {
            return false; // If they are not the same, the sentence is not circular
        }
      
        // Iterate over the string starting from the second character
        for (int i = 1; i < length; ++i) {
            // Check if the current character is a space and the character before it
            // is not the same as the character after it
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false; // If they are not the same, the sentence is not circular
            }
        }
      
        // If all checks pass, the sentence is circular
        return true;
    }
};
