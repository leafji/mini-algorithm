#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class stringSolution {

public:

    bool isValid(char s) {
        if ((s >= 'a' && s <= 'z') || 
            (s >='A' && s <= 'Z') || 
            (s >= '0' && s <= '9')) 
            return true;
        else 
            return false;
    }

    bool equal (char a, char b) {
        if (a >= 'A' && a <= 'Z') {
            a += 'a' - 'A';
        }
        if (b >= 'A' && b <= 'Z') {
            b += 'a' - 'A';
        }
        return a == b;
    }

    /*lc验证回文串, 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写*/
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            /* 双指针一个指向头， 一个指向尾， 判断是否是回文串 */
            while(i < s.size() && !isValid(s[i])) i++;
            while(j > 0 && !isValid(s[j])) j--;
            
            if (i < j && !equal(s[i], s[j])) return false;
            else i++, j--;
        }
        return true;
    }
};

int main() {
    
    stringSolution s1;
    string str1 = "testset";
    cout << "isPalindrome:"  << s1.isPalindrome(str1) << endl;
    return 0;
}