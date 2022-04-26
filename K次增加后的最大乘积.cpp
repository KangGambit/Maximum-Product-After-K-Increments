#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    const int LIMIT = (int)1E9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        int size = nums.size();
        long long pro = 1;
        if (size == 1) return (int)pro * (nums[0] + k);
        sort(nums.begin(), nums.end());
        for (int p = 1; p < size && k != 0; p++) {
            int p0 = 0;
            while (nums[p] != nums[p0] && k != 0) {
                int dif = nums[p] - nums[p0];

                if (k >= (dif * p)) {
                    k -= (dif * p);
                    for (int i = p - 1; i >= 0; i--) {
                        nums[i] += dif;
                    }
                }

                else {
                    int val = k / p;
                    int n = k % p;
                    for (int i = p - 1; i >= 0 && val != 0; i--) {
                        nums[i] += val;
                    }
                    for (int i = n; i > 0; i--) {
                        nums[p0] += 1;
                        p0++;
                    }
                    k = 0;
                }
            }
        }
        if (k != 0) {
            int val = k / size;
            int n = k % size;
            for (int i = n - 1; i >= 0; i--) {
                nums[i] += val + 1;
            }
            for (int i = size - 1 - n; i >= 0; i--) {
                nums[i] += val;
            }
        }
        for (int i = 0; i < size; i++) {
            pro = (pro * nums[i]) % LIMIT;
        }
        return (int)pro;
    }

};

int main() {
    vector<int> nums = { 24, 5, 64, 53, 26, 38 };
    Solution slt;
    int res = slt.maximumProduct(nums, 54);
    cout << res << endl;
    return 0;
}