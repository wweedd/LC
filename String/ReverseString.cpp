/*
 * Write a function that reverses a string. The input is given as an array
 * of characters char[].
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra money.
 * You may assume all the characters consists of printable ascii characters.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    void reverseString(vector<char> &s) {
        int lptr(0);
        int rptr(s.size() - 1);
        while (lptr < rptr) {
            if (s[lptr] != s[rptr]) {
                std::swap(s[lptr], s[rptr]);
            }
            ++lptr;
            --rptr;
        }
        return;
    }
};
