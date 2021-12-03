/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int resevernum=0;
    while (x>resevernum)
    {
        resevernum=x%10+resevernum*10;
        x/=10;
    }
    return x==resevernum/10||x==resevernum;
}
// @lc code=end
