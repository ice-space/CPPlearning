#include <bits/stdc++.h>

using namespace std;

struct CompareS
{
    bool operator()(const pair<int, pair<int, int>> &v1, const pair<int, pair<int, int>> &v2)
    {
        if (v1.second.second < v2.second.second)
        {
            return false;
        }
        else if (v1.second.second == v2.second.second)
        {
            if (v1.second.first >= v1.second.first)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CompareS> pq;
    pair<int, pair<int, int>> temp;
    int n = 0;
    int i = 1;
    int begin = 0;
    int end = 0;
    int count = 0;
    vector<vector<int>> choose;
    vector<int> temp_choose;

    vector<priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CompareS>> pqv;

    cin >> n;
    while (i <= n)
    {
        cin >> begin >> end;
        temp = make_pair(i, make_pair(begin, end));
        pq.push(temp);
        i++;
    }
    pqv.push_back(pq);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CompareS> new_pq;
    pqv.push_back(new_pq);

    int last_end_time = -1;
    while (count < n)
    {

        auto top = pqv.front().top();
        pqv.front().pop();
        int start = top.second.first;
        int end = top.second.second;

        if (start > last_end_time)
        {
            temp_choose.push_back(top.first);
            last_end_time = end;
            ++count;
        }
        else
        {
            pqv.back().push(top);
        }
        if (pqv.front().empty())
        {
            swap(pqv.front(), pqv.back());
            last_end_time = -1;
            choose.push_back(temp_choose);
            temp_choose.clear();
        }
    }

    for (int i = 0; i < choose.size(); i++)
    {
        cout << "牛栏编号：" << i << "中牛的个数" << choose[i].size() << endl;
        for (auto iter : choose[i])
        {
            cout << iter << " ";
        }
        cout << endl;
    }

    return 0;
}
