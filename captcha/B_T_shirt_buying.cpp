#include<iostream>
#include<bits/stdc++.h>
#include<string>    
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<long long int>price(n);
    vector<int>front_color(n);
    vector<int>back_color(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>front_color[i];
    }
    for(int i=0;i<n;i++){
        cin>>back_color[i];
    }
    long long int buy;
    cin>>buy;
    vector<int>buy_color(buy);
    vector<int>pricee_color(buy);
    vector<int>result(buy,-1);
    for(int i=0;i<buy;i++){ 
        cin>>buy_color[i];
    }
    for(int i=0;i<buy;i++){
        vector<int>pricee_color;
        for(int j=0;j<n;j++){
        if(buy_color[i]==front_color[j] || buy_color[i]==back_color[j]){
            pricee_color.push_back(price[j]);
        }
        }
        int min_price;
         if (!pricee_color.empty()) {
             min_price = *min_element(pricee_color.begin(), pricee_color.end());
            result[i] = min_price;
         
        auto it=find(price.begin(),price.end(),min_price);
        int index = distance(price.begin(), it);

        price[index] = -1;
        front_color[index] = -1; 
        back_color[index] = -1; 
        
         }  
    }
    for(int i=0;i<buy;i++){
        cout<<result[i]<<" ";
    }

}
/* optimised approach

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector<long long int> price(n);
    vector<int> front_color(n);
    vector<int> back_color(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> front_color[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> back_color[i];
    }
    
    long long int buy;
    cin >> buy;
    vector<int> buy_color(buy);
    vector<int> result(buy, -1);

    for (int i = 0; i < buy; i++) {
        cin >> buy_color[i];
    }

    // Maps to store the prices by color
    map<int, multiset<long long int>> color_to_prices;
    
    for (int i = 0; i < n; i++) {
        color_to_prices[front_color[i]].insert(price[i]);
        color_to_prices[back_color[i]].insert(price[i]);
    }

    for (int i = 0; i < buy; i++) {
        int color = buy_color[i];
        if (color_to_prices[color].empty()) {
            result[i] = -1;
        } else {
            long long int min_price = *color_to_prices[color].begin();
            result[i] = min_price;

            // Remove the min_price from all relevant color sets
            color_to_prices[front_color[distance(price.begin(), find(price.begin(), price.end(), min_price))]].erase(color_to_prices[front_color[distance(price.begin(), find(price.begin(), price.end(), min_price))]].find(min_price));
            color_to_prices[back_color[distance(price.begin(), find(price.begin(), price.end(), min_price))]].erase(color_to_prices[back_color[distance(price.begin(), find(price.begin(), price.end(), min_price))]].find(min_price));

            // Mark the t-shirt as used
            price[distance(price.begin(), find(price.begin(), price.end(), min_price))] = -1;
        }
    }

    for (int i = 0; i < buy; i++) {
        cout << result[i] << " ";
    }

    return 0;
}


*/