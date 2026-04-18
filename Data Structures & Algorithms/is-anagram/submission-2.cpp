class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> charMap;

        for (int i = 0; i < s.size(); i++)
        {
            char charS = s[i];
            char charT = t[i];
            charMap[charS] = charMap[charS] + 1;
            charMap[charT] = charMap[charT] -1;
        }

        for (const auto& [key, value] : charMap)
        {
            if (value)
            {
                return false;
            }
        }
        
        return true;
    }
};
