//
//  main.cpp
//  Backpack_Greedy_Weight__Value
//
//  Created by 오관윤 on 2023/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Carrier
{
public:
    int weight;
    int value;
    
    Carrier(int weight, int value)
    {
        this->weight = weight;
        this->value = value;
    }
    
    bool operator<(const Carrier& other)const
    {
        
    }
    
};

vector<pair<int,int>> carry;

int main(int argc, const char * argv[]) {
    
    cout << "Hello, World!\n";
    
    int n,maxWeight;
    cin >> n >> maxWeight;
    int value,weight;
    
    for(int i=0; i<n; i++)
    {
       
        cin>> weight >>value;
        carry.push_back(make_pair(weight, value));
    }
    
    sort(carry.begin(), carry.end());
    
    int count =n;
    int sameWeight =carry[0].first;
    int capacity = maxWeight;
    int totalValue=0;
    
    for(int i=1; i<n; i++)
    {
        if(carry[i].first == carry[i-1].first)
        {
            sameWeight = carry[i].first;
            totalValue += carry[i].second;
            
        }
        else
        {
            sameWeight = carry[i].first;
            capacity -= sameWeight;
            if(capacity <0)
            {
                capacity += sameWeight;
                break;
            }
            totalValue += carry[i].second;
        }
    }
    
    cout << totalValue;
    
    // 동일 무게일경우 가치가 더 높으면 선택
    // 배낭에 넣을 수 있는 물건들의 가치합의 최대값을 출력
    
    return 0;
}
