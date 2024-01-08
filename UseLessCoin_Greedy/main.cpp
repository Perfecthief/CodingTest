//
//  main.cpp
//  UseLessCoin_Greedy
//
//  Created by 오관윤 on 2023/11/08.
//

#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int> v;
int main(int argc, const char * argv[]) {
    // 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
    
    //동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
    
    cin>>n>>k;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    int count =0;
    
    for(int i=0; i<v.size(); i++)
    {
        int coins = v[n-(1+i)];
        count += k/coins;
        k %=  coins;
    }
    
    cout << count <<endl;
    return 0;
}
