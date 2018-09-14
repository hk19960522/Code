#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct T
{
    int r;
    int c1,c2;
};

int main()
{
    int n,m;
    while ( scanf("%d%d ",&n,&m) == 2 ) {
        map<string,int> StrIndex;
        vector<string> v[10001];
        string Data;
        int cur = 0;
        T Ans1 , Ans2 ;
        bool isFinal = 0;
        for (int i=0;i<n;i++)
        {
            getline(cin , Data);

            int indexFront = 0,indexBack = 0;
            for (int j=0;j<m;j++) {
                indexBack = Data.find(',',indexFront);
                string newStr = Data.substr(indexFront,indexBack-indexFront);
                indexFront = indexBack+1;
                v[i].push_back(newStr);
                if ( StrIndex.find(newStr) == StrIndex.end() ) {
                    StrIndex[ newStr ] = ++cur;
                }
            }
        }
        for (int j=0;j<m && !isFinal;j++) {
            for (int k=j+1;k<m && !isFinal;k++) {
                map<long long,int> DB;
                for (int i=0;i<n;i++){
                    long long IndexA = StrIndex[ v[i][j] ] , IndexB = StrIndex[ v[i][k] ];
                    IndexA = IndexA * 100000 + IndexB;
                    if ( DB.find(IndexA) == DB.end() ) {
                        DB[ IndexA ] = i;
                    }
                    else {
                        cout << "NO\n" << DB[ IndexA ]+1 << " " << i+1 << endl << j+1 << " " << k+1 << endl;
                        isFinal = 1;
                        break;
                    }
                }
            }
        }
        if ( !isFinal ) {
            cout << "YES\n";
        }
    }
    return 0;
}
