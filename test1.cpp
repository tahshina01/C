#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        for (int bin = 1; bin <= n; ++bin) {
			cout<<str<<" bin "<<bin<<endl;
            if (n % bin != 0) continue;

            vector<vector<int>> here(bin, vector<int>(26, 0));
            for (int i = 0; i < n; ++i) {
                here[i % bin][str[i] - 'a']++;
            }
            int expect = n / bin;
			cout<<expect<<" e b "<<bin<<endl;

            int totaldif = 0;
            for (auto c : here) {

                int dif = INT_MAX;
				cout<<"bin "<<bin<<endl;
                for (int k : c) {

					cout<<k<<" ";
                    dif = min(dif, expect - k);
                }
				cout<<endl;
                totaldif += dif;
            }
            if (totaldif <= 1) {
                cout << bin << endl;
                break;
            }
        }
    }

    return 0;

}
