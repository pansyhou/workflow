/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start

//第一先找最大长度//

char * longestCommonPrefix(char ** strs, int strsSize){、

    /* 纵向扫描 */
    if(strsSize==0)return "";
    for(int i=0;i<strlen(strs[0]);i++)
    {
        for (int k=0;k<strsSize;k++)
        {
            if(strs[k][i]!=strs[0][i])
            {
                strs[0][i]='\0';
                return strs[0];
            }
        }
    }
    return strs[0];

    /* 横向扫描 */
    // if(strsSize==0)return "";
    // for(int i=0;i<strlen(strs[0]);i++)
    // {
    //     for (int k=0;k<strsSize;k++)
    //     {
    //         if(strs[0][i]!=strs[k][i])
    //         {
    //             strs[0][i]='\0';
    //             return strs[0];
    //         }
    //     }
    // }
    // return strs[0];
}
// @lc code=end

