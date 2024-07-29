#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    cin >> a;

    while (a > 0) {
        int n, f, k;
        cin >> n >> f >> k;

        vector<int> v(n + 1); // We use 1-based indexing for the vector

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }

        // Sort the in non-increasing order
        int index_element=v[f];
        sort(v.begin() + 1, v.end(), greater<int>());

        // Find the index of the favorite cube
        //cout<<index_element;
        int index1,ind;
        auto it=find(v.begin()+1,v.end(),index_element);
        if(it!=v.end()){
             index1=it-v.begin();
            
        }    
         // cout<<index1;
        bool flag_initk = false;
            for (int j = 1 ; j <= k; j++) {
                if (v[j] == index_element) {
                    flag_initk = true;
                    break;
                }
            }
            // Check if it appears after the first k cubes
            bool flag = false;
            for (int j = k+1 ; j <= n; j++) {
                if (v[j] == index_element) {
                    flag = true;
                    break;
                }
            }
            if (!flag_initk) {
                cout << "NO" << endl;
            } else {
                if(flag){
                    cout << "MAYBE" << endl;
                }
                else{
                    cout << "YES" << endl;
                }
                
            }
        

        a--;
    }

    return 0;
}
