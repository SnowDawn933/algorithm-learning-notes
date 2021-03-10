#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int w, G, a[30010];
  scanf("%d%d", &w, &G);
  for (int i = 1; i <= G; i++)
  {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + G);
  int i, j;
  i = 1;
  j = G;
  int cnt = 0;
  while (i <= j)
  {
    if (a[i] + a[j] <= w)
    {
      cnt++;
      i++;
      j--;
    }
    else
    {
      cnt++;
      j--;
    }
  }
  
  printf("%d", cnt);
  return 0;
}