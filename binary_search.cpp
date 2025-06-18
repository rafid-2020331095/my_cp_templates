class Solution {
public:
    int manual_lower_bound(const vector<int>& v, int target) {
        int left = 0, right = v.size() - 1;
        int ans = v.size();  // no >= target → returns v.size()
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] >= target) {
                ans = mid;
                right = mid - 1; // search left half
            } else {
                left = mid + 1;  // search right half
            }
        }
        return ans;
    }

    int manual_upper_bound(const vector<int>& v, int target) {
        int left = 0, right = v.size() - 1;
        int ans = v.size();  // no > target → returns v.size()
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] > target) {
                ans = mid;
                right = mid - 1; // search left half
            } else {
                left = mid + 1;  // search right half
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int x = manual_lower_bound(nums, target);
        int y = manual_upper_bound(nums, target);

        // Debug print if needed
        // cout << "lower_bound: " << x << ", upper_bound: " << y << endl;

        if (x == nums.size() || nums[x] != target) {
            return {-1, -1};
        }
        return {x, y - 1};
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};


    vector<int> searchRange(vector<int>& nums, int target) {
        int x = lower_bound(nums.begin(),nums.end(), target)-nums.begin();
        int y = upper_bound(nums.begin(),nums.end(), target)-nums.begin();

        // Debug print if needed
        // cout << "lower_bound: " << x << ", upper_bound: " << y << endl;

        if (x == nums.size() || nums[x] != target) {
            return {-1, -1};
        }
        return {x, y - 1};
    }
