#include <iostream>
using namespace std;

const int maxn = 1010;
string s, ans;
int len;
bool used[maxn] = {0};

void dfs(int index) {
  if (index == len) cout << ans << "\n";

  for (int i = 0; i < len; ++i)
    if (!used[i]) {
      ans[index] = s[i];
      used[i] = true;
      dfs(index + 1);
      used[i] = false;
    }
}

int main() {
  string s = "222";
  len = s.length();
  ans = s;
  sort(s.begin(), s.end());
  dfs(0);
  return 0;
}

/**
 * #include <iostream>
 * #include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));
    return 0;
}
*/