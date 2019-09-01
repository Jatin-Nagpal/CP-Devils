#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


#define pii pair <int,int>
bool cmp(pii a, pii b) {
    return a.ff < b.ff || (a.ff == b.ff && a.ss < b.ss); }
bool cw(pii a, pii b, pii c) {
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) < 0; }
bool ccw(pii a, pii b, pii c) {
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) > 0; }
void convex_hull(vector <pii> &a) {
    if (a.size() == 1)
        return;
    sort(a.begin(), a.end(), &cmp);
    pii p1 = a[0], p2 = a.back();
    vector<pii> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}