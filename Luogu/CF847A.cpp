#include <iostream>
using namespace std;
const int maxn = 100 + 5;

int n, head;
struct node
{
    int lef, rig, val;
} a[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].lef >> a[i].rig;
        a[i].val = i;
        if (!head && !a[i].lef)
        {
            head = a[i].val;
        }
    }
    int num = head;
    while (a[num].rig != head)
    {
        bool flag = true;
        if (a[num].rig)
        {
            num = a[num].rig;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == head)
                {
                    continue;
                }
                if (!a[i].lef)
                {
                    a[i].lef = a[num].val;
                    a[num].rig = a[i].val;
                    num = a[i].val;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].lef << " " << a[i].rig << endl;
    }
}