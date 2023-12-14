#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Status {
	int lv, hp, mhp;
	int dist;
	Status(int lv, int hp, int mhp, int dist = 0): lv(lv), hp(hp), mhp(mhp), dist(dist) {}
};

bool vis[20][310][410];

int main() {
	int lv, hp, mhp, mdmg;
	int dmg[20], hl[20];
	cin >> lv >> hp >> mhp >> mdmg;
	for (int i = 1; i <= lv; i++)
		cin >> dmg[i] >> hl[i];

	queue<Status> q;
	q.push(Status(1, hp, mhp ,0));
	while (!q.empty()) {
		Status s = q.front();
		if (!s.mhp)
			break;
		q.pop();

		// level up
		// ���i�H���L�̤j����
		// ��q�n����צ�Ǫ�������
		if (s.lv < lv && s.hp > mdmg) {
			Status t(s.lv + 1, s.hp - mdmg, s.mhp, s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}

		// attack
		// �Ǫ���HP �֩�ثe���Ū�����
		// �]���ڭ̬O����A�ҥH�u�n�����N��ӧQ
		// �p�G�S��
		// ���N�ܤ֥ثe���ͩR����Ǫ�������
		if (s.mhp - dmg[s.lv] <= 0 || s.hp - mdmg > 0) {
			Status t(s.lv, s.hp - mdmg, max(0, s.mhp - dmg[s.lv]), s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}

		// heal
		if (hl[s.lv] > mdmg) {
            ///-mdmg �n��~��
			Status t(s.lv, min(hp, s.hp + hl[s.lv]) - mdmg, s.mhp, s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}
	}
	if (q.empty())
		cout << -1 << endl;
	else
		cout << q.front().dist << endl;
	return 0;
}
