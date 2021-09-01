//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,popcnt,tune=native")
#include<bits/stdc++.h>
#define INF 1e9
#define EPS 1e-9
#define FAST_INPUT ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
#define ll long long
#define f(i, a, b)  for(int i = a; i <b; i++)
#define FOR(a, b) for (int(a) = 0; (a) < (b); (a)++)
#define FORL(a, b) for (long long int (a) = 1; (a) <= (b); (a)++)
#define print cout <<
using namespace std;

bool wildcardMatch(string s, string p, int n,int m)
{
    // base case
    if (m == 0)  return (n == 0);

    int i = 0, j = 0, StringPointer = -1, patternPointer = -1;
    while (i < n)
    {
        if (s[i] == p[j]) i++, j++ ;
        else if (j < m && p[j] == '?') i++, j++ ;
        else if (j < m && p[j] == '*')
        {
            StringPointer = i;
            patternPointer = j;
            j++;
        }
        else if (patternPointer != -1)
        {
            j = patternPointer + 1;
            i = StringPointer + 1;
            StringPointer++;
        }
        else
            return false;
    }



    return ((j==m)?true :false); 
}

int main()
{
    string s , p ;
    cin >> s >> p ;
    cout << (wildcardMatch(s, p , s.size() , p.size())?"true" : "false") ;

   return 0 ;
}
