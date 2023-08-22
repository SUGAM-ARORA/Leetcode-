class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if not columnNumber:
            return ""
        columnNumber, remainder = divmod(columnNumber - 1, 26)
        return self.convertToTitle(columnNumber) + chr(65 + remainder)