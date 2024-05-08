/* ¹þÏ£±í */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2005] = { 0 };
        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++;
        }

        int isExist[1005] = { 0 };
        for (int i = 0; i < 2005; i++) {
            if (hash[i] != 0) {
                if (isExist[hash[i]] != 0) return false;
                isExist[hash[i]]++;
            }
        }

        return true;
    }
};