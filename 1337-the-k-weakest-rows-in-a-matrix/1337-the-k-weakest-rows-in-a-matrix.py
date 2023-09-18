# Import the necessary functions from modules
from operator import itemgetter
from heapq import nlargest

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        # Define a function to extract the index from a tuple
        index_getter = itemgetter(0)
        
        # Define a custom key function to determine row strength
        key_func = lambda t: (-sum(t[1]), -t[0])
        
        # Use enumerate to create an iterable of tuples (index, row)
        enumerated_rows = enumerate(mat)
        
        # Use nlargest to find the k weakest rows based on the custom key function
        weakest_rows = nlargest(k, enumerated_rows, key=key_func)
        
        # Map the index_getter function to extract row indices and convert the result to a list
        result = list(map(index_getter, weakest_rows))
        
        return result
        