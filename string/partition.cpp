#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<bool> > f;
    vector<vector<string> >  res;
    vector<string> ans;
    /*
      给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
      回文串 是正着读和反着读都一样的字符串。
      思路： 1. 首先构造一个dfs字符串所有的子串。
            2. 构造一个二维数组f[i][j] 表示从i到j 的子串是否是回文字符串。
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1]
                即，首尾相同，且内部也为回文字符串。
            3. 遍历dfs，如果是回文字符串，放入答案中。
    */
   // dfs 方法遍历字符串的所有可拆分的子串
   // dfs 的第二个参数表示，从i开始截断 比如abcd 从0 开始截断为a  bcd，因此整个组合为a + dfs(1)
   // 也可以从1开始截断，为ab + dfs(2) 而dfs 内部靠栈来维护一次分割的结果，每次进入一次dfs 都会切割一次，因此就会入栈一次。
   // 比如 abc  a切割，入栈， b， c 后入栈， c 循环完成后一次分割结束， c出栈， 循环到bc 入栈。
   void dfs(string s, int i) {
      if (i == s.size()) {
          res.push_back(ans);
          return;
      }

      for (int j = i; j < s.size(); j++) {
           if (f[i][j]) {
               ans.push_back(s.substr(i, j - i + 1));
               dfs(s, j + 1);
               ans.pop_back();
           } 
     }
   }
   vector<vector<string> > partition(string s) {
       int n = s.size();
       f.assign(n, vector<bool>(n, true));
       // 注意这里必须倒着算，因为正者算对于f[1][k] 这种 f[2][k -1]很可能还没有计算完成
       for (int i = n - 1; i >= 0; i--)
           for (int j = i + 1; j < n; j++)
               f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
       dfs(s, 0);
       for (int i = 0; i < res.size(); i++) {
           for (int j = 0; j < res[i].size(); j++)
               cout << res[i][j] << " ";
           cout << endl;
       }
       return res;
    }
};

int main() {
    
    Solution s1;
    string str1 = "ababa";
    vector<vector<string> > res = s1.partition(str1);
    
    return 0;
}