class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string> dictionary) {
        std::unordered_map<int, int> cache;

        int result = dfs(s, dictionary, cache);
        return result;
    }

private:
    int dfs(const std::string& text, const std::vector<std::string>& dictionary, std::unordered_map<int, int>& cache) {
        if (text.empty()) {
            return 0;
        }

        if (cache.find(text.length()) != cache.end()) {
            return cache[text.length()];
        }

        int minimum = text.length();

        for (const std::string& word : dictionary) {
            if (text == word) {
                minimum = 0;
                cache[text.length()] = minimum;
                return minimum;
            } else if (text.substr(0, word.length()) == word) {
                int result = dfs(text.substr(word.length()), dictionary, cache);
                minimum = std::min(minimum, result);
            }
        }

        int result = 1 + dfs(text.substr(1), dictionary, cache);
        minimum = std::min(minimum, result);

        cache[text.length()] = minimum;
        return minimum;
    }
};