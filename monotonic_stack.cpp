// monotonic stack is applied to optimzely find the next or prev,greater or smaller elment in o(n) from brute force o(n^2)
//6,4,3,10,12,15,4 try a dry run u will understand

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}


vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
