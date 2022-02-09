#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

class Solution {
public:
    /**
     * Brute force algorithm
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i]))
                return {hash[target -nums[i]], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};

void print_ret(vector<int> array) {
    for (auto i : array) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    vector<int> array = {1, 2, 4, 7, 10};
    Solution solution;
    print_ret(solution.twoSum(array, 3));
    print_ret(solution.twoSum2(array, 3));
    return 0;
}

