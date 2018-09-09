#include <iostream>

#include <vector>

using namespace std;

/*
题目：
    一个UTF8字符串的长度可能是1到4个字节。其编码规则如下：
      对于1字节的UTF-8字符，第一个bit是0，后面的bit都是它的unicode码；
      对于n字节的UTF-8字符，前n个bits都是1，第n+1bit是0，接下来n-1个字节的前两个bits都是10。
    例如：
      Char number range        |       UTF-8 octet sequence
      (Hexadecimal)            |       (Binary)
      0000 0000 ~ 0000 007F    |       0xxxxxxx
      0000 0080 ~ 0000 07FF    |       110xxxxx 10xxxxxx
      0000 0800 ~ 0000 FFFF    |       1110xxxx 10xxxxxx 10xxxxxx
      0001 0000 ~ 0010 FFFF    |       11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    给定一个整数数组表示的数据，判断其是否是合法的UTF-8编码
    注意：每个整数只有最低8位用于存储数据。即：输入的每个整数代表一个byte。
输入描述：
    第一行一个整数，代表数组长度N
    第二行空格分隔的N个整数
输出描述：
    1代表合法，0代表不合法
示例：
    输入，
        3
        197 130 1
    输出
    1
*/

class Solution
{
public:
    bool isLegalUnicode(int size, vector<int> & vec_int)
    {
        if ((1 > size) || (4 < size))
            return false;
        int size_tmp = vec_int.size();
        if (size != size_tmp)
            return false;
        
        vector<char> vec_ch;
        for (int i = 0; i < size; i++)
        {
            int tmp = vec_int[i];
            if ((0 > tmp) || (255 < tmp))
                return false;
            vec_ch.push_back((char)tmp);
        }

        for (int i = 0; i < size;)
        {
            int class_tmp = getClass(vec_ch[i]);
            if (0 == class_tmp)
                return false;
            vector<char> vec_ch_sub(vec_ch.begin() + i, vec_ch.begin() + i + class_tmp);
            if (false == isUnicode(vec_ch_sub))
                return false;
            i += class_tmp;
            if (i == size)
                break;
            if (i > size)
                return false;
        }
        return true;
    }

private:
    int getClass(char ch)
    {
        int res = 1;
        char flag = (char)128;
        char tmp = (char)128;
        for (int i = 0; i < 8; i++)
        {
            if (flag == (flag & ch))
            {
                res++;
                tmp /= 2;
                flag += tmp;
            }
            else
            {
                break;
            }
        }
        if (res > 4)
            res = 0;
        if (res > 1)
            res--;
        return res;
    }

    bool isUnicode(vector<char> & vec_ch)
    {
        int size = vec_ch.size();

        if (1 == size)
        {
            if (0 == (0x80 & vec_ch[0]))
                return true;
            return false;
        } 
        else
        {
            int bit_flag = 0;
            int bit_tmp = 256;
            for (int i = 0; i < size; i++)
            {
                bit_tmp /= 2;
                bit_flag += bit_tmp;
            }
            int bit_cmp = bit_flag;
            bit_flag += (bit_tmp / 2);

            if (bit_cmp != (bit_flag & vec_ch[0]))
                return false;
            
            bit_cmp = 128;
            bit_flag = 192;
            for (int i = 1; i < size; i++)
            {
                if (bit_cmp != (bit_flag & vec_ch[i]))
                    return false;
            }
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    int size = 3;
    int array [3] = {197, 130, 1};
    vector<int> vec_int(array, array+3);
    cout << solution.isLegalUnicode(size, vec_int) << endl;
    return 0;
}