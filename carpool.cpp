#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<float,float>>> gtime;
struct car
{
	bool available;
	int car_n;
	vector<vector<pair<float,float>>> Time;
	string car_owner;
	pair<float,float> P;
	float r;
	car(bool available = false,int a=0,pair<float,float> p=make_pair(0,0),float rr = 0,string co = "",vector<vector<pair<float,float>>> htime = gtime)
	{
		Time = htime;
		car_n = a;
		P = p;
		r = rr;
		car_owner = co;
	}
};
vector<car> carid(1,car());
vector<vector<car> > v(1000000,carid);

void add_node(car ncar)
{
	bool flag = false;
	for(int i=0;i<v.size();i++)
	{

	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i].size()==1)
			continue;
		else
		{
			if(sqrt(pow((ncar.P.first-v[i][0].P.first),2)+pow((ncar.P.second-v[i][0].P.second),2))+(ncar.r)<=v[i][0].r)
				{
					v[ncar.car_n].push_back(v[i][0]);
					flag = true;
				}
			else if(sqrt(pow((ncar.P.first-v[i][0].P.first),2)+pow((ncar.P.second-v[i][0].P.second),2))+(v[i][0].r)<=ncar.r)
				v[i].push_back(ncar);
		}
	}
	if(!flag)
		v[0].push_back(ncar);
}


void in_owner()
{
	int a;
	float b;
	string s;
	vector<vector<pair<float,float>>> Time;
	Time.resize(7);
	pair<float,float> p;
	cin>>a;
	cin>>p.first>>p.second;
	cin>>b;
	cin>>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			int day;
			cin>>day;
			Time[day].resize(1);
			cin>>Time[day][0].first>>Time[day][0].second;
		}
	car ncar(true,a,p,b,s,Time);
	add_node(ncar);
}

vector<car> ans;
bool check(car caro,pair<float,float> start,pair<float,float> end,int d,int t)
{
	bool flag=false;
	int r1=sqrt(pow((caro.P.first-start.first),2)+pow((caro.P.second-start.second),2)),r2=sqrt(pow((caro.P.first-end.first),2)+pow((caro.P.second-end.second),2));
	if(max(r1,r2)<=caro.r)
	{
		for(int i=0;i<caro.Time.size();i++)
		{
			if(caro.Time[i].size()!=0&&i==d)
			{
				if(caro.Time[d][0].first<=t&&caro.Time[d][0].second>=t)
					flag=true;
			}
		}
	}
	return flag;
}


void dfs(int s,vector<bool> &visited,pair<float,float> start,pair<float,float> end,int day,int Tim)
{
	//cout<<s<<endl;
	for(int i=0;i<v[s].size();i++)
	{
		//cout<<v[s].size()<<endl;
		if(v[s].size()==1)
			continue;
		else
		{
			if(!visited[i])
			{
				if(check(v[s][i],start,end,day,Tim))
				{
					ans.push_back(v[s][i]);
				}
				else
				{
					visited[i] = true;
					dfs(v[s][i].car_n,visited,start,end,day,Tim);
				}	
			}
		}
	}
		
}

 void display(car caro,int d)
 {
 	cout<<caro.car_n<<endl;
 	cout<<caro.car_owner<<endl;
 	cout<<caro.Time[d][0].first<<"-"<<caro.Time[d][0].second<<endl;
 }

void in_commuter()
{
	int day,Tim;
	pair<float,float> start;
	pair<float,float> end;
	ans.resize(0);
	cin>>start.first>>start.second;
	cin>>end.first>>end.second;
	cin>>day>>Tim;
	vector<bool> visited(1000000);
	visited[0] = true;
	dfs(0,visited,start,end,day,Tim);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		display(ans[i],day);
	}
}

int main()
{
	bool t;
	while(true)
	{	cin>>t;
		if(t)
			{
				in_owner();
			}
		else
			{
				in_commuter();
			}
	}
}
/*
1
1
1 2
1 
A
2
0 12 22
4 12 22
1
2
4 2
2 
B
2
0 12 22
4 12 22
1
3
3 2
.25
C 
2
0 12 22
4 12 22
1
4
3 2
.5 
D
2
0 12 22
4 12 22
1
5
3 2
3
E 
2
0 12 22
4 12 22
0 
3 1.9 3 2.1 4 17
*/
