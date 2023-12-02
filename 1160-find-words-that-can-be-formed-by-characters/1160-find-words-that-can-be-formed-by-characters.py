class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def can_form(word, chars):
            char_count = Counter(chars)
            for char in word:
                if char_count[char] <= 0:
                    return False
                char_count[char] -= 1
            return True
        result = 0
        for word in words:
            if can_form(word, chars):
                result += len(word)
        return result