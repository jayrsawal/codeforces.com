//
//  c1070pA.cpp
//  codeforces
//
//  Created by Victor Ignacio Jr. Sawal on 2018-11-22.
//  Copyright © 2018 Victor Ignacio Jr. Sawal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int getSum(int x) {
    string s = to_string(x);
    int sum = 0;
    for(char i : s) {
        sum += (int)i - (int)48;
    }
    return sum;
}

struct branch {
    string s = " ";
    int rem = 0;
    int sum = 0;
} b;

int main(int argc, const char * argv[]) {
    cout << "go: ";
    int d, s;
    cin >> d >> s;
    bool visited[500][5000];
    queue<branch> q;
    b = (branch) {.s=" ", .rem=0, .sum=0};
    q.push(b);
    while(!q.empty()) {
        branch x = q.front();
        q.pop();
        for(int i=0; i<=9; i++) {
            char c = '0'+i;
            string str = x.s + c;
            int rem = (x.rem*10+i) % d;
            int sum = x.sum + i;
            if(sum > s || visited[rem][sum]) continue;
            if(rem==0 && sum==s) {
                cout << str;
                return 0;
            } else {
                q.push( (branch){.s=str, .rem=rem, .sum=sum} );
                visited[rem][sum] = true;
            }
        }
    }
    cout << "-1";
// the naive method takes too long
//    int min = s/9;
//    int start = (pow(10, min) / d);
//    start = start * d + d;
//    while(getSum(start) != s) {
//        start += d;
//    };
//    cout << start;
}
