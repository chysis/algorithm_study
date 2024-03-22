#include <iostream>
#include <string>

using namespace std;

int main()
{
    int d = 666;
    int n, m = 1;
    cin >> n;

    while (n > m)
    {
        d++;
        string s = to_string(d);
        if (s.find("666")!=string::npos)
            m++;
    }
    cout << d;
}