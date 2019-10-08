#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int map[1000][1000];

struct point2d {
	int x, y;
};
vector<point2d> ripe;

void Result()
{
	int m, n;	
	scanf("%d %d", &m, &n);
	
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d", &map[i][j]);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(map[i][j]==1){
				point2d tmp={j,i};
				ripe.push_back(tmp);
			}

	int days=0;
	bool changed=false;

	do
	{
		changed=false;
		long ripeCount = ripe.size();

		for(long i=0;i<ripeCount;++i)
		{
			int x = ripe[i].x;
			int y = ripe[i].y;
			if(y>0   && map[y-1][x]==0){ 
				map[y-1][x]=1;
				point2d tmp={x,y-1}; 
				ripe.push_back(tmp);
				changed=true; 
			}
			if(x>0   && map[y][x-1]==0){ 				
				map[y][x-1]=1; 
				point2d tmp={x-1,y}; 
				ripe.push_back(tmp); 
				changed=true; 
			}
			if(y<n-1 && map[y+1][x]==0){ 
				map[y+1][x]=1; 
				point2d tmp={x,y+1}; 
				ripe.push_back(tmp); 
				changed=true; 
			}
			if(x<m-1 && map[y][x+1]==0){ 
				map[y][x+1]=1; 
				point2d tmp={x+1,y}; 
				ripe.push_back(tmp);
				changed=true; 
			}
		}

		ripe.erase(ripe.begin(), ripe.begin() + ripeCount);

		if(changed==false)break;

		days++;
	}while(true);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(map[i][j]==0){
				printf("-1");
				return;
			}

	printf("%d", days);
}

int main()
{
	Result();
	getchar(); getchar();
}