#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

class Solution {
public:

    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl) {
        std::vector<std::string> table;
        // std::vector<int> codes;
        
        std::string enUrl = "";
        int enInt = 0;

        for (int i = 0; i < longUrl.length(); i++) {
            std::string str = std::string(1, longUrl[i]);
            for (int x = 1; x < longUrl.length() - i; x++) {
                std::vector<std::string>::iterator it = std::find(table.begin(), table.end(), str + std::string(1, longUrl[i + x]));
                // std::cout << (it != table.end());
                if (it == table.end()) {// no
                    std::vector<std::string>::iterator index = find(table.begin(), table.end(), str);
                    if (str.length() == 1) enUrl += str + " ";
                    else enUrl += std::string(1, (uint8_t)(126 + index - table.begin() + 1)) + " ";
                    std::cout << 126 + index - table.begin() + 1 << std::endl;
                    table.push_back(str + std::string(1, longUrl[i + x]));
                    str = "";
                    break;
                } else { //yes
                    str += std::string(1, longUrl[i + x]);
                    if (i + x == longUrl.length() - 1) {
                        std::vector<std::string>::iterator index = find(table.begin(), table.end(), str);
                        if (str.length() == 1) enUrl += str + " ";
                        else enUrl += std::string(1, (uint8_t)(126 + index - table.begin() + 1)) + " ";
                    }
                    enInt++;
                    // i++;
                }
                std::cout << str << std::endl;
            }
            i += enInt;
            enInt = 0;
        }
        std::cout << enUrl << std::endl;
        return enUrl;
    }

    // Decodes a shortened URL to its original URL.
    // std::string decode(std::string shortUrl) {
        
    // }
};

int main() {
    Solution().encode("sdsdsdsds");
    return 0;
}
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));