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

bool checkOperator(char op)
{
    return ((op == '+'||op == '-')? true : false);
}

int dooperations(int a, int b, char op)
{
    switch(op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
}
int go(string str)
{
    stack <int> numbers;
stack <char> operators;

    f(i,0,str.length())
    {
        if(str[i] == ' ')
            continue;
        else if(str[i] == '(')
        {
            operators.push(str[i]);
        }
        else if(isdigit(str[i]))
        {
            int number = 0;
            while(i < str.length() && isdigit(str[i]))
            {
                number = (number*10) + (str[i]-'0');
                i++;
            }

            numbers.push(number);

            i--;
        }
        else if(str[i] == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                int n2 = numbers.top();
                numbers.pop();

                int n1 = numbers.top();
                numbers.pop();

                char op = operators.top();
                operators.pop();

                numbers.push(dooperations(n1, n2, op));
            }
            if(!operators.empty())
                operators.pop();
        }
        else
        {

            while(!operators.empty() && checkOperator(operators.top()) >= checkOperator(str[i]))
            {
                int n2 = numbers.top();
                numbers.pop();

                int n1 = numbers.top();
                numbers.pop();

                char op = operators.top();
                operators.pop();

                numbers.push(dooperations(n1, n2, op));
            }

            operators.push(str[i]);
        }
    }

    while(!operators.empty())
    {
        int n2 = numbers.top();
        numbers.pop();

        int n1 = numbers.top();
        numbers.pop();

        char op = operators.top();
        operators.pop();

        numbers.push(dooperations(n1, n2, op));
    }

    return numbers.top();
}

int main()
{
    string s ;
    cin >> s ;
    cout << go(s) << endl ;
    return 0;
}
