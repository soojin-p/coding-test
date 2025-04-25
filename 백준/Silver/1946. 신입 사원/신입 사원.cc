#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	//한개의 회의실

	int T; // 테스트케이스, 지원자 수
	cin >> T ;
	// 성적, 면접 순위

	for(int t=0; t<T; t++){
		int N;
		cin >> N;
		vector<pair<int, int>> v(N);
		int top = N;

		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
			return a.second < b.second;
			});
		top = v[0].first;
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (v[i].first < top) {
				cnt++;
				top = v[i].first;
			}
		}
		cout << cnt<<"\n";
	}

	return  0;
}