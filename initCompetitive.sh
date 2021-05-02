#!/bin/bash

# cd ./Codeforces
CONTEST_NAME="DUT_Training_2_5_2021"
PROBLEMS=(A B C D E F G H I J K L M N O)
# PROBLEMS=(A B C D E)

if [ -d "$CONTEST_NAME" ]; then
  echo "Direction existed"
  exit 1
fi

mkdir $CONTEST_NAME

cd $CONTEST_NAME
for problemName in "${PROBLEMS[@]}" #(1)
do #(1)

mkdir $problemName #(1)
cd $problemName #(1)
cat > data.cpp <<- "EOF"
#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  return 0;
}
EOF

touch data.inp
touch data.out

cd ..

done #(1)

echo "Create contest successfully"
