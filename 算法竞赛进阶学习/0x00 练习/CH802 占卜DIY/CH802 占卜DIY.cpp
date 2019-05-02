#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

pair<deque<int>, int> heap[14];
int kcnt;

void play() {
	if (!kcnt) return;
	int q = heap[13].first[0]; heap[13].first.pop_front();
	while (true) {
		if (q == 13) {
			--kcnt, play();
			return;
		}
		heap[q].fi
	}
}