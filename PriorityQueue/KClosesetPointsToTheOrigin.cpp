#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


typedef pair<int, int> pi;
typedef pair<int, pi> ppi;

typedef vector<pair<int, int>> vpi;
typedef priority_queue<ppi> heap;

vpi KClosestPointsToTheOrigin(vpi& points, int k) {
	vpi vt; // vector of points
	heap mh; // max heap {key-diff^2, val-point}

	for (pi it : points) {
		int key = it.first * it.first + it.second * it.second;
		mh.push({ key, it });
		if (mh.size() == k) {
			mh.pop();
		}
	}

	while (!mh.empty()) {
		vt.push_back(mh.top().second);
		mh.pop();
	}

	return vt;
}