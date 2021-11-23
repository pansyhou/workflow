/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x)
{
    long ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    return (int)ans == ans ? (int)ans: 0;
}
// @lc code=end

