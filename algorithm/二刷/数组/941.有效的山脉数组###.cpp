/* Ë«Ö¸Õë */
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        int left = 0;
        int right = arr.size() - 1;
        while (left + 1 < arr.size() && arr[left] < arr[left + 1]) {
            left++;
        }

        while (right - 1 >= 0 && arr[right] < arr[right - 1]) {
            right--;
        }

        if (left == arr.size() - 1 || right == 0) return false;

        return left == right;
    }
};