#include<iostream>
#include<queue>
using namespace std;

// ���� �ٸ� �� �ö� Ʈ����
queue<int> waitTruckQueue;
// ����, �� �Ÿ�
queue<pair<int, int>> goingTruckQueue;
// �ӽ÷� 1 �����ִ� ť
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
		// �ٸ� �� Ʈ���� 1ĭ ����, �����ϸ� Pop
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
		// ��� Ʈ�� �� �� ������ ���� �� ť�� Push
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
		// �� ���������� Ȯ��
		if (waitTruckQueue.empty() && goingTruckQueue.empty())
			break;
	}

	cout << time;
	return 0;
}