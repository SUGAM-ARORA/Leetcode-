class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        for (const string& word : words) {
            string tempChars = chars;
            bool valid = true;
            for (char c : word) {
                size_t pos = tempChars.find(c);
                if (pos != string::npos) {
                    tempChars.erase(pos, 1);
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result += word.size();
            }
        }
        return result;
    }
};