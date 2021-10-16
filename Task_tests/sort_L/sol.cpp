#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 1001;
const int MAXL = 100;

int n, p[MAXN];
char s[MAXN][MAXL + 1];

bool les(const int &a, const int &b)
{
  static char b1[MAXL * 2 + 1], b2[MAXL * 2 + 1];
  sprintf(b1, "%s%s", s[a], s[b]);
  sprintf(b2, "%s%s", s[b], s[a]);
  return strcmp(b1, b2) > 0;
}

int main()
{
  // assert(freopen("number.in", "rt", stdin));
  // assert(freopen("number.out", "wt", stdout));

  n = 0; 
  while (scanf("%s", s[n]) == 1)
    p[n] = n, n++;

  sort(p, p + n, les);
  for (int i = 0; i < n; i++)
    printf("%s", s[p[i]]);
  puts("");
  return 0;
}