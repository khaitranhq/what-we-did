#!/bin/bash

# cd ./Codeforces

### =========================== edit here

CONTEST_NAME="DUT_Training_2_5_2021"
ACTUAL_CONTEST_NAME="2018 ICPC South Central USA Regional Contest"
PROBLEMS=(A B C D E F G H I J K L)
# PROBLEMS=(A B C D E)

### =========================== automated generation below 

### =========================== CREATING CONTEST DIR
if [ -d "$CONTEST_NAME" ]; then
  echo "Directory existed"
  exit 1
fi

mkdir $CONTEST_NAME
cd $CONTEST_NAME

echo "Creating contest subdirectory.."
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
echo "Create contest successfully."

### ================================ CREATING EDITORIAL
# cd is at root/contest_name
echo "Creating Team's Editorial (/contest/readme.md).."

if [ -e "readme.md" ]; then
  echo "readme.md already exists. Aborting."
  exit 1
fi

touch readme.md

echo "# $ACTUAL_CONTEST_NAME" >> readme.md
echo "## Tổng quan" >> readme.md

table_top="|"
table_sep="|"
table_bot="|"

for problemName in "${PROBLEMS[@]}" #(1)
do #(1)
  table_top="$table_top[$problemName](#${problemName,})|"
  table_sep="$table_sep-------|"
  table_bot="$table_bot  N/A  |"
done #(1)

echo $table_top >> readme.md
echo $table_sep >> readme.md
echo $table_bot >> readme.md
echo "" >> readme.md

echo "Ký hiệu: " >> readme.md
echo '1. `N/A`: Not attempted' >> readme.md
echo '2. `SOL`: Solved within the contest time' >> readme.md
echo '3. `SWH`: Solved with hint (from tutorial, solutions,... or from any external material), in the contest time' >> readme.md
echo '4. `UPS`: Upsolved - solved after the contest' >> readme.md
echo '5. `NAC`: Not accepted - failed during contest, not yet upsolved' >> readme.md
echo "" >> readme.md

echo "## Cụ thể" >> readme.md

for problemName in "${PROBLEMS[@]}" #(1)
do #(1)
echo "### $problemName" >> readme.md
echo "[Link to submission]($problemName/data.cpp)" >> readme.md
echo "" >> readme.md
echo "" >> readme.md
done #(1)

echo "Successfully created readme.md"

### ================================ APPENDING TO /README.md
# cd is at root/contest_name
echo "Appending new contest data to (/README.md).."

cd ..
echo "## $ACTUAL_CONTEST_NAME" >> readme.md
echo '* `As: "'$CONTEST_NAME'"`' >> readme.md
echo "" >> readme.md
echo '* `Timestamp: '`date`'`' >> readme.md
echo "" >> readme.md
echo "* [Link to directory]($CONTEST_NAME)" >> readme.md
echo "" >> readme.md

echo "Appending successfully. Exiting."