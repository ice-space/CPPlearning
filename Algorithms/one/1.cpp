#include<bits/stdc++.h>

using namespace std;

int josephus(int n,int m);

int main()
{   
    int n=0,m=0;
    while(cin >> n >> m ){
        if(n==0 && m ==0){
            break;
        }else{
            cout << josephus(n,m) << endl;
        }
    }
    cin.clear();
    return 0;
}


int josephus(int n, int m)  {
    if( n ==1 ){
        return 1;
    }else{
        return (josephus(n - 1, m) + m - 1) % n + 1;
    }
}
