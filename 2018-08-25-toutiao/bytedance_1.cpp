#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <string>

using namespace std;

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