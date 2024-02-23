class Solution {
public:
    int mod(int a, int n) {
        if (a < 0) {
            a = a + n;
        }
        return a % n;
    }

    int search(vector<int>& nums, int target) {
        int k = nums.size();
        int index = 0;
        for (int i = 0; i < k - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                index = i + 1;
                break;
            }
        }

        int low = 0;
        int high = k - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int newmid = mod((mid + index), k);

            if (nums[newmid] == target) {
                return newmid;
            } else if (nums[newmid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
