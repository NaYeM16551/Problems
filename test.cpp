#include <iostream>
#include <string>

using namespace std;




string removeAdjacentDuplicates(string s) {
    // Initialize an empty string to store the result
    string result = "";
    result.push_back(s[0]);

    // Iterate through the input string
    for (int i = 1; i < s.length(); i++) {
        // If the current character is not a duplicate of the previous character, append it to the result
        if (s[i] != s[i - 1]) {
            result += s[i];
        }
    }

    // Return the result
    return result;
}

string removeA(string s) {

    string ans;
    int i = 0;
    while (s[i]) {
        if (s[i] != s[i + 1])
            ans += s[i];
        else {
            while (s[i] == s[i + 1])
                i++;
        }
        i++;


    }
    if (ans.size() == s.size())
        return ans;
    return removeA(ans);

}
int main() {
    // Test the function with a few different strings
    cout<<removeA("a");


    return 0;
}
