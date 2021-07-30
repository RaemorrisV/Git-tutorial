#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int arr[1000001];
long long int binarysearch(long long int start, long long int end, long long int num, long long int treelen)
{
  long long int s = start;
  long long int e = end;
  long long int length = (end + start) / 2;
 // cout << length << endl;
  while (s <= e)
  {
    long long int tree = 0;
    for (int i = 1; i <= num; i++)
    {
      if (arr[i] - length>=0)
      {
        tree += (arr[i] - length);
      }
      else if (arr[i] - length<0)
      {
        tree+=0;
      }
    }
    if (tree >= treelen)
    {
      s = length + 1;
      length = (s + e) / 2;
      	//cout << length << endl;
      tree = 0;
    }
    else
    {
      e = length - 1;
      length = (s + e) / 2;
      //	cout << length << endl;
      tree = 0;
    }
  }
  return length;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1); //이분 탐색을 위한 sort를 위해서

  cout << binarysearch(0,arr[n], n, m) << '\n';
  return 0;
}