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
                    if (str.length() == 1) enUrl += str;
                    else enUrl += std::string(1, (uint8_t)(126 + index - table.begin() + 1));
                    table.push_back(str + std::string(1, longUrl[i + x]));
                    str = "";
                    break;
                } else { //yes
                    str += std::string(1, longUrl[i + x]);
                    if (i + x == longUrl.length() - 1) {
                        std::vector<std::string>::iterator index = find(table.begin(), table.end(), str);
                        if (str.length() == 1) enUrl += str;
                        else enUrl += std::string(1, (uint8_t)(126 + index - table.begin() + 1));
                    }
                    enInt++;
                    // i++;
                }
            }
            i += enInt;
            enInt = 0;
        }
        return enUrl;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl) {
        std::string decode = "";
        std::vector<std::string> table;
        std::string prive = std::string(1, shortUrl[0]);

        decode += shortUrl[0];
        table.push_back(std::string(1, shortUrl[0]) + std::string(1 ,shortUrl[1]));

        for (int i = 1; i < shortUrl.length(); i++) {
            std::string str = "";
            std::cout << (int)(uint8_t)shortUrl[i] << std::endl;
            if ((int)(uint8_t)shortUrl[i] <= 126) {
                decode += shortUrl[i];
                str = shortUrl[i];
            } else {
                int index = (int)(uint8_t)shortUrl[i] - 127;
                // std::cout << table[index] << std::endl;
                str = table[index];
                decode += table[index];
                std::cout << table[index] << std::endl;
                
            }
            table.push_back(prive + str[0]);
            // std::cout << str << std::endl;
            // std::cout << prive + str.substr(0, str.length() - 2) << std::endl;
            prive = str;
        }
        for (int i = 0; i < table.size(); i++) {
            std::cout << table[i] << std::endl;
        }
        return decode;
    }
};

int main() {
    Solution a = Solution();
    std::string b = a.encode("sdsdsdsds");
    std::string c = a.decode(b);
    std::cout << c << std::endl;
    return 0;
}