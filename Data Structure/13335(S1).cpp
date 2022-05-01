#include<iostream>
#include<queue>
using namespace std;

// 아직 다리 안 올라간 트럭들
queue<int> waitTruckQueue;
// 무게, 간 거리
queue<pair<int, int>> goingTruckQueue;
// 임시로 1 더해주는 큐
queue<pair<int, int>> tempQueue;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int w;
	int L;

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		waitTruckQueue.push(weight);
	}

	int time = 0;
	int weightSumOnBridge = 0;
	while (1)
	{
		time += 1;
		// 다리 위 트럭들 1칸 전진, 도착하면 Pop
		while (goingTruckQueue.empty() == false)
		{
			int weight = goingTruckQueue.front().first;
			int distance = goingTruckQueue.front().second;
			goingTruckQueue.pop();
			tempQueue.push(make_pair(weight, distance));
		}

		while (tempQueue.empty() == false)
		{
			int weight = tempQueue.front().first;
			int distance = tempQueue.front().second;
			distance += 1;
			tempQueue.pop();
			if (distance < w)
			{
				goingTruckQueue.push(make_pair(weight, distance));
			}
			else
			{
				weightSumOnBridge -= weight;
			}
		}
		// 대기 트럭 갈 수 있으면 전진 후 큐에 Push
		if (waitTruckQueue.empty() == false)
		{
			int nextTruckWeight = waitTruckQueue.front();
			if (nextTruckWeight + weightSumOnBridge <= L)
			{
				goingTruckQueue.push(make_pair(nextTruckWeight, 0));
				weightSumOnBridge += nextTruckWeight;
				waitTruckQueue.pop();
			}
		}
		// 다 지나갔는지 확인
		if (waitTruckQueue.empty() && goingTruckQueue.empty())
			break;
	}

	cout << time;
	return 0;
}