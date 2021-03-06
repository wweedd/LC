/*
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a
 * letter in patter and a non-empty word in str.
 *
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    if (pattern.empty()) {
      for (char ch : str)
        if (ch != ' ') return false;
      return true;
    }
    str.push_back(' ');
    string mapp[128]{};
    unordered_set<string> visited;
    int start{0};
    for (int i = 0; i < pattern.size(); ++i) {
      while (str[start] == ' ' && start < str.size()) ++start;
      if (start == str.size()) return false;
      auto end = str.find_first_of(' ', start);
      auto currWord = str.substr(start, end - start);
      start = end;
      if (mapp[pattern[i]].empty()) {
        if (visited.find(currWord) != visited.end()) return false;
        mapp[pattern[i]] = currWord;
        visited.insert(currWord);
      } else if (mapp[pattern[i]] != currWord) {
        return false;
      }
    }
    while (str[start] == ' ' && start < str.size()) ++start;
    return start == (int)str.size();
  }
};
