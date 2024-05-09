class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int area = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            } 
            else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            }
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        area += (min(height[left], height[right]) - height[mid]) * (right - left - 1);
                    }
                }
                st.push(i);
            }
        }
        return area;
    }
};