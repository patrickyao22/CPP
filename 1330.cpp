#include<bits/stdc++.h>
using namespace std;
int dira[12] = {1,1,2,2,-1,-1,-2,-2,2,2,-2,-2}; 
int dirb[12] = {2,-2,1,-1,2,-2,1,-1,2,-2,2,-2}; 
int p1x,p1y,p2x,p2y;
int ans=0;
bool flag[100][100];
struct node {
	int x;
	int y;
	int step;
};
queue<node> p1;
queue<node> p2;
bool finish(int x,int y) {
	if (x == 1 && y == 1){
		return true;
	}
	return false;
}
bool check(int x,int y) {
	if (x < 1 || y < 1) {
		return false;
	}
	if (x > 100 || y > 100) {
		return false;
	}
	return true;
}
int main() {
	
	memset(flag, false, sizeof(flag));
	cin >> p1x >> p1y >> p2x >> p2y;
	ans = -1;
	p1.push({p1x,p1y,0});
	p2.push({p2x,p2y,0});
	while (not p1.empty()) {
		node temp = p1.front();
		p1.pop();
		if (finish(temp.x,temp.y)) {
			cout << temp.step << endl;
			break;
		}
		for (int i=0;i<12;i++) {
			int nx = temp.x + dira[i];
			int ny = temp.y + dirb[i];
			
			if (not check(nx,ny)) {
				continue;
			}
			if (flag[nx][ny]) {
				continue;
			}
			flag[nx][ny] = true;
			p1.push({nx,ny,temp.step+1});
		}
	}
	memset(flag, false, sizeof(flag));
	while (not p2.empty()) {
		
		node temp = p2.front();
		p2.pop();
		if (finish(temp.x,temp.y)) {
			
			cout << temp.step << endl;
			return 0;
		}
		for (int i=0;i<12;i++) {
			int nx = temp.x + dira[i];
			int ny = temp.y + dirb[i];
			
			if (not check(nx,ny)) {
				
				continue;
			}
			if (flag[nx][ny]) {
				
				continue;
			}
			flag[nx][ny] = true;
			p2.push({nx,ny,temp.step+1});
		}
	}
	
	return 0;
	
}
