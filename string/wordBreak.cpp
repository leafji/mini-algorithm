#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> gDict;
    string ans = " ";

    bool checkstring(string substr, vector<string>& wordDict) {
        for (auto d : wordDict) {
            if (substr == d) {return true;}
        }
        return false;
    }
    /*
     *  给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
     *  说明：
     *  拆分时可以重复使用字典中的单词。
     * 你可以假设字典中没有重复的单词。
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        /* dp[i] 表示从0 到 i 可以的子串可以被字典里的单词拆分 */
        // dp[i] 是true 的前提是存在j 从0 到 i- 1， dp[j] 是true， 从j+1 到i 的子串在dict 中
        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        cout << s.size() << endl;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && checkstring(s.substr(j, i - j), wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        for (auto d : dp) cout << d << " ";
        cout << endl;
        return dp[s.size()];
    }

    /* 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，
    使得句子中所有的单词都在词典中。返回所有这些可能的句子。*/

    string getString(string s) {
        for (auto d : gDict) {
            if (d == s) return s;
        }
        return "";
    }

    void dfs(string s, int from) {
        if (from >= s.size()) {
            res.push_back(ans.substr(1, ans.size() - 2));
            return;
        }

        for (int i = from; i < s.size(); i++) {
            string r = getString(s.substr(from, i - from + 1));
            if (r.size()) {
                ans.append(r + " ");
                dfs(s, i + 1);
                ans.pop_back();
                while(ans.back() != ' ' && s.size()) ans.pop_back();
            }
        }
    }
    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        gDict = wordDict;
        dfs(s, 0);
        return res;
    }
};

int main() {
    
    Solution s1;
    string str1 = "pineapplepenapple";
    const char *str[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> dict;
    for (auto s : str) {
        dict.push_back(s);
    }
    //cout << s1.wordBreak(str1, dict);
    vector<string> r = s1.wordBreak2(str1, dict);
    for (auto ss : r) cout << ss << endl;
    return 0;
}