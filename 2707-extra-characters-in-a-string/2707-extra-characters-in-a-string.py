class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        cache = {}

        def dfs(text):
            if len(text) <= 0:
                return 0

            if len(text) in cache:
                return cache[len(text)]
            
            minimum = len(text)

            for word in dictionary:
                if text == word:
                    minimum = 0
                    cache[len(text)] = minimum
                    return minimum

                elif text[:len(word)] == word:
                    result = dfs(text[len(word):])
                    minimum = min(minimum, result)

            minimum = min(minimum, 1 + dfs(text[1:]))

            cache[len(text)] = minimum

            return minimum

        return dfs(s)
        