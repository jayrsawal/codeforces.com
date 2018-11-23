//
//  main.cpp
//  codeforces
//
//  Created by Victor Ignacio Jr. Sawal on 2018-11-22.
//  Copyright © 2018 Victor Ignacio Jr. Sawal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool traverse(set<int> &used, vector<set<int> > edges, int start, int goal) {
    // if we've used all our vertices, give up
    if(used.size() == edges.size()) return false;
    used.insert(start);
    set<int> v = edges[start];
    // if no connections to vertex, give up
    if(v.size() == 0) return false;
    // if we have direct connection from start to goal, success
    if(v.count(goal)==1) return true;
    // look for next unused vertex to traverse
    for(set<int>::iterator i = v.begin(); i != edges[start].end(); ++i) {
        int vertex = *i;
        if(used.count(vertex)==1) continue;
        if(traverse(used, edges, vertex, goal)) return true;
        if(used.size() == edges.size()) return false;
    }
    return false; // catch all
}

int main(int argc, const char * argv[]) {
    int n, m, a, b, c, q, u, v;
    cin >> n >> m;
    // collect m amount of edges for n vertecies
    vector<vector<int>> edge(m, vector<int>(3));
    map<int, vector<set<int>>> colors;
    // save n vectors of respective sets of connected vertices by color
    for(unsigned int i  = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(colors.count(c)==0){
            colors.insert(pair<int,vector<set<int>> >(c, vector<set<int> >(n,set<int>())));
        }
        colors[c][a-1].insert(b-1);
        colors[c][b-1].insert(a-1);
    }
    // collect q amount of queries
    cin >> q;
    vector<int> ans;
    map<int, vector<set<int>>>::iterator it;
    // accept search questions
    for(unsigned int i = 0; i < q; i++) {
        cin >> u >> v;
        u--;
        v--;
        int a = 0;
        // iterate by color
        for(it = colors.begin(); it != colors.end(); it++) {
            vector<set<int> > e = it->second;
            // skip if there are no connections to either u or v
            if(e[u].size()==0||e[v].size()==0) continue;
            if(e[u].count(v)==1) {
                // solved if there is a direct connection
                a += 1;
            } else {
                // we have connections from u, find path to v
                set<int> used;
                if(traverse(used, e, u, v)) a+= 1;
            }
        }
        ans.push_back(a);
    }
    // print our answers for all queries
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
}
