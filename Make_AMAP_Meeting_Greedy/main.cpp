//
//  main.cpp
//  Make_AMAP_Meeting_Greedy
//
//  Created by 오관윤 on 2023/11/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    Meeting(int start , int end)
    {
        this -> start = start;
        this -> end = end;
    }
    bool operator< (const Meeting& other) const
    {
        return this->end != other.end ? this->end < other.end : this->start < other.start;
    }
};

vector<pair<int,int>> schedule;
vector<Meeting> v;
int n;
int result(1);
int main(int argc, const char * argv[]) {

    
    
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int begin,end;
        cin >>begin>>end;
        v.push_back(Meeting(begin ,end));
        //schedule.push_back(make_pair(end, begin));
        // 끝나는 시간이 중요.
        //정렬할때 큰수부터 작은순으로 정렬되니 <12, 9> , <11 ,8> , <12 ,8>을 정렬한다 하면 <12 ,9> ,<12,8> <11,8> 순으로 정렬
        //자연스럽게 끝나는 시간 기준으로 정렬 되며 두 시간 사이의 길이가 적은 순 부터 정렬이 된다.
        
        /**
         make_pair(begin , end)순으로 해보자
         시작 순으로 정렬 되어 <9,12>, <8,12>,<8,11>순으로 저장 될 테니 애매 하다.
            ? 왜요 이것도 가장 적은 시간순으로 배치 되잖아요
            schedule[0].first; 이부분을 .second로 바꾸면 되지만 직관적이지 못하다
            알고리즘을 만드는데 사용하는 시간은 30 분이 적정시간인데 직관적이지 못하면 정렬하는 과정에서 오류가 생겨 코드를 만드는데 오랜 시간이 걸릴 수 있다. 이점을 유의 하자.
            시작 시간이 <12,12>가 있을 경우와 <11,12>가 있는 경우를 생각해보자
            
         **/
    }
    
    
    //sort(schedule.begin(), schedule.end());
    sort(v.begin(), v.end());
    
    //int time = schedule[0].first;
    int time = v[0].end;
    
    int count =1;
    for(int i=0; i<n; i++)
    {
        if(time <= v[i].start)
        {
            count++;
            time = v[i].end;
        }
    }
    
    /*
    한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
     */
    
    /*
     첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.
     */
    cout << count;
    
    return 0;
}
