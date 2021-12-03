/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start


int romanToInt(char * s)
{
    int roma[26];
    roma['I'-'A']=1;
    roma['V'-'A']=5;
    roma['X'-'A']=10;
    roma['L'-'A']=50;
    roma['C'-'A']=100;
    roma['D'-'A']=500;
    roma['M'-'A']=1000;
    int sum=0,len=strlen(s);
    for (int i=0;i<len;i++)
    {
        int value = roma[s[i] - 'A'];
        if (i < len - 1 && value < roma[s[i + 1] - 'A'])
        {
            sum -= value;
        } else {
            sum += value;
        }
    }
    return sum;
}
// @lc code=end

