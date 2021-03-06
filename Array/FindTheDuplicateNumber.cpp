/*
 * Given an array nums containing n+1 integers where each integer
 * is between 1 and n (inclusive), prove that at least one duplicate
 * number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be
 * repeated more than once.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};
