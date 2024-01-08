//
//  main.cpp
//  CodingTest
//
//  Created by 오관윤 on 2023/11/06.
//
// 큰 수의 법칙 (a.k.a 그리디 알고리즘)
#include <iostream>


using namespace::std;

int n, m , k;
vector<int> v;

int main(int argc, const char * argv[]) {

    //N개의 배열을 받고 , 주어진 수 중 가장 큰 수를 만드는 것. M번 더하는데, K번을 초과하여 더할순 없다.
    
    //공백을 기준으로 N M K입력받기
    cin >> n >> m >> k;
    
    //N개의 수를 공백을 기준으로 구분하여 입력 받기
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end()); // 입력 받은 수들 정렬하기
    int first = v[n-1]; // 가장 큰 수
    int second = v[n-2]; // 두번째로 큰 수
    
    int cnt = (m/(k+1))*k;
    cnt += m%(k+1);
    //핵심 부분. 예시로 가장 큰 수 6과 그 다음 큰 수 5를 받고, M이 8이고, K가 3 이라면 반복되는 수열은 { 6, 6, 6, 5}가 반복될 것이다.
    //그러니 수열의 길이는 K+1(마지막에 다음 큰 수를 더해야하니) M을 K+1로 나눈 횟수가 된다. 여기에 k번을 곱하면 반복되는 수열만큼 할 수 있다.
    //하지만 M이 K+1로 완전히 나누어 질 수 없는 경우에 수가 있으니 (M % K+1)을 더해주어야 한다.
    
    
    int result =0;
    result += cnt *first;
    result += (m-cnt) *second;
    
    cout << result <<'\n';
    return 0;
}
