class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        
        unordered_map<int, vector<int>> valueToIndex;
        for (int i = 0; i < n; i++) {
            valueToIndex[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) {
                    return steps;
                }
                
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                for (int index : valueToIndex[arr[curr]]) {
                    if (!visited[index]) {
                        visited[index] = true;
                        q.push(index);
                    }
                }
                
                // remove the indices with the same value to avoid revisiting them
                valueToIndex.erase(arr[curr]);
            }
            steps++;
        }
        
        return -1;
    }
};
