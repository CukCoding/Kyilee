#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, p;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> p;
			v[i].push_back(p);
		}
	}
	int result = INT_MAX;

	int minNum = INT_MAX;
	// 값, 반 번호, 학생 번호
	priority_queue<pair<int, pair<int,int>>> pq;

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end(),greater<int>());
		minNum = min(minNum, v[i][0]);
		pq.push({ v[i][0],{i,0} });
	}
	
	while (pq.size()>0) {
		int maxNum = pq.top().first;
		int maxIndex = pq.top().second.first;
		int maxArrIndex = pq.top().second.second;

		pq.pop();

		result = min(result, maxNum - minNum);

		if (maxArrIndex + 1 == M) {
			break;
		}
		minNum = min(minNum, v[maxIndex][maxArrIndex + 1]);
		pq.push({ v[maxIndex][maxArrIndex + 1] ,{maxIndex,maxArrIndex + 1} });
		

		
	}

	cout << result << endl;;


	

	return 0;
}