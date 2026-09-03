#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        std::vector<std::vector<std::string>> res;
        for (auto& [k, v] : mp)
            res.push_back(v);
        return res;
    }
};