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
    // vector<int> choose;

    cin >> n;
    while (i <= n)
    {
        cin >> begin >> end;
        temp = make_pair(i, make_pair(begin, end));
        pq.push(temp);
        i++;
    }

    int last_end_time = -1;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int movie_start = top.second.first;
        int movie_end = top.second.second;

        if (movie_start >= last_end_time)
        {
            last_end_time = movie_end;
            ++count;
        }
        // if(choose.empty()){
        //     begin = pq.top().second.first;
        //     end = pq.top().second.second;
        //     choose.push_back(pq.top().first);
        //     count++;
        //     pq.pop();
        // }
        // if(pq.top().second.first >= end){
        //     begin = pq.top().second.first;
        //     end = pq.top().second.second;
        //     choose.push_back(pq.top().first);
        //     count++;
        //     pq.pop();
        // }else{
        //     pq.pop();
        // }
    }

    cout << count << endl;
    return 0;
}
