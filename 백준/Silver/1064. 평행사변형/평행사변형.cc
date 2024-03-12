#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    double res, l, s;
    vector<double> v;

    if ((yb - ya) * (xc - xb) == (xb - xa) * (yc - yb))
    {
        cout << "-1";
        return 0;
    }
    v.push_back(sqrt(pow((xb - xa), 2) + pow((yb - ya), 2))+ sqrt(pow((xc - xb), 2) + pow((yc - yb), 2)));
    v.push_back(sqrt(pow((xc - xb), 2) + pow((yc - yb), 2))+ sqrt(pow((xc - xa), 2) + pow((yc - ya), 2)));
    v.push_back(sqrt(pow((xc - xa), 2) + pow((yc - ya), 2))+ sqrt(pow((xb - xa), 2) + pow((yb - ya), 2)));
    l = *max_element(v.begin(), v.end());
    s = *min_element(v.begin(), v.end());
    
    res = 2*l-2*s;
    cout.precision(10);
    cout << res;
}