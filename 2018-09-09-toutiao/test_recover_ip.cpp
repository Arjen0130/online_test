#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*
题目：
    工程师小张的代码出Bug了。
    在上报用户IP的时候，漏掉了"."符号，例如 10.0.0.1 变成了 10001。
    请你帮小张对这些异常数据进行处理，还原出所有可能的原始IP，输出可能的原始IP的数量。
输入：
    第一行一个字符串，代表抹掉.符号的IP
输出：
    一行一个整数，表示答案
示例：
    输入，
        8888
    输出
        1
*/

class Solution
{
public:
    int possibleNumOfIp(string ip)
    {
        int len = ip.length();
        if ((len < 4) || (len > 12))
            return 0;
        
        vector<vector<int> > parts_num;

        for (int p1 = 1; p1 < 4; p1++)
            for (int p2 = 1; p2 < 4; p2++)
                for (int p3 = 1; p3 < 4; p3++)
                    for (int p4 = 1; p4 < 4; p4++)
                    {
                        if (len == (p1 + p2 + p3 + p4))
                        {
                            vector<int> tmp(4);
                            tmp[0] = p1;
                            tmp[1] = p2;
                            tmp[2] = p3;
                            tmp[3] = p4;
                            parts_num.push_back(tmp);
                        }
                    }
        vector<vector<string> > parts_str;
        for (int i = 0; i < parts_num.size(); i++)
        {
            vector<string> tmp_str;
            vector<int> part_num = parts_num[i];
            int num_sta = 0;
            for (int j = 0; j < 4; j++)
            {
                int num_len = part_num[j];
                tmp_str.push_back(ip.substr(num_sta, num_len));
                num_sta += num_len;
            }
            parts_str.push_back(tmp_str);
        }

        int ret = 0;
        for (int i = 0; i < parts_str.size(); i++)
        {
            if (true == isIp(parts_str[i]))
                ret++;
        }
        return ret;
    }

private:
    bool isIp(vector<string> & vec_str)
    {
        int size = vec_str.size();
        if (4 != size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (false == isIpNum(vec_str[i]))
                return false;
        }
        return true;
    }
    bool isIpNum(string str)
    {
        int size = str.size();
        if ((0 >= size) || (4 <= size))
            return false;
        
        int num = 0;
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if ((0 == num) && ('0' == str[i]))
                flag = true;
            char c_tmp = str[i];
            if ((c_tmp < '0') || (c_tmp > '9'))
                return false;
            num *= 10;
            num += c_tmp - '0';
        }

        if ((num < 0) || (num > 255))
            return false;
        if (((true == flag) && (num != 0)) || ((num == 0) && (size != 1)))
            return false;
        return true; 
    }

    
};

int main()
{
    Solution solution;
    cout << solution.possibleNumOfIp("10101010") << endl;
    return 0;
}
