#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <string>

using namespace std;

/*
题目：
    Bytedance Efficiency Engineering 团队在8月20日搬入了学清嘉创大厦。
    为庆祝团队的乔迁之喜，字节君决定邀请整个 EE 团队，举办一个大型团建游戏 -- 字节跳动大闯关。
    可是，遇到了一个问题：
        EE 团队共有 n 个人，大家都比较害羞，不善于与陌生人交流。
        这 n 个人每个人都向字节君提供了自己认识的人的名字，不包括自己。
        如果 A 的名单里有 B，或 B 的名单里有 A，则代表 A 与 B 互相认识。
        同时，如果 A 认识 B， B 认识 C，则代表 A 与 C 也会很快的认识，毕竟通过 B 的介绍，两个人就可以很快互相认识了。
    为了大闯关游戏可以更好地团队协作、气氛更加活跃，并使得团队中的人可以尽快的互相了解、认识和交流，
    字节君决定根据这个名单，将团队分为 m 组，每组人数可以不同，但组内的任何一个人都与组内的其他所有人直接或间接的认识和交流。
    如何确定一个方案，使得团队可以分成 m 组，并且这个 m 尽可能地小呢？
输入：
    第一行一个整数 n，代表有 n 个人，从 1 开始编号。
    接下来有 n 行，第 x+1 行代表编号为 x 的人认识的人的编号 k (1<=k<=n)，每个人的名单以 0 代表结束。
输出：
    一个整数 m，代表可以分的最小的组的个数。
*/

class Solution {
public:
    int group_count(vector<vector<int> > & know_list)
    {
        int count = 0;
        int size = know_list.size();

        int remain = size;
        vector<bool> v_flag;
        for (int i = 0; i < size; i++)
        {
            v_flag.push_back(true);
        }

        int person_pos = -1;
        while (remain > 0)
        {
            person_pos = find_person(person_pos, v_flag);
            vector<int> person;
            if (-1 == person_pos)
            {
                return count;
            }
            else
            {
                v_flag[person_pos] = false;
                person = know_list[person_pos];
                remain--;
            }

            if (0 == person[0])
            {
                count++;
                continue;
            }
            else
            {
                find_know(person, know_list, count, v_flag, remain);
                count++;
            }
        }
        return count;
    }

    int find_person(int pre_person_pos, vector<bool> & v_flag)
    {
        int person_pos = -1;
        int size = v_flag.size();
        for (int i = pre_person_pos+1; i < size; i++)
        {
            if (v_flag[i])
            {
                person_pos=i;
                break;
            }
        }
        return person_pos;
    }

    void find_know(vector<int> person, vector<vector<int> > & know_list, 
    int & count, vector<bool> & v_flag, int & remain)
    {
        int person_size = person.size() - 1;
        for(int i = 0; i < person_size; i++)
        {
            int know_item = person[i];
            if (v_flag[know_item - 1])
            {
                v_flag[know_item - 1] = false;
                remain--;
                vector<int> more_person = know_list[know_item - 1];
                find_know(more_person, know_list, count, v_flag, remain);
            }
        }
    }
    
};

int main()
{
    ifstream cin("cc_test1_cin.txt");
    vector<vector<int> > input;
    int num;
    cin >> num;
    int count = 0;
    while (count < num)
    {
        vector<int> know_list;
        int know_item;
        do
        {
            cin >> know_item;
            know_list.push_back(know_item);
        }while  (0 != know_item);
        input.push_back(know_list);
        count++;
    }

    Solution solution;
    cout << solution.group_count(input) << endl;
    return 0;
}