#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	//한개의 회의실

	int N; // 회의 수
	cin >> N;

	vector<pair<int,int>> v(N);

	for (int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}

	// 종료시간 기준 정렬
	sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});

	int cnt = 0;
	int endtime = 0;

	// 회의시간 겺치지 않게 선택

	for (auto& meeting : v) {
		if (meeting.first >= endtime) {
			cnt++;
			endtime = meeting.second;
		}
	}
	cout << cnt;
	return  0;
}