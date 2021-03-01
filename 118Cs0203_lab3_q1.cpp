#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 30;
int n, e, v1, v2, s, d, pkt_cnt, pkt_sz,k;
vector<int> g[MAX_NODES];

struct PacketInfo{
	int curr, count_val, time_elapsed;
};

struct PacketParentInfo{
	int curr, count_val, time_elapsed, parent;
};
struct Packet_K_Info{
	int curr, count_val, time_elapsed,K;
};

int bfs_all_lines(int src, int dest, int cnt){
	queue<PacketInfo> q;
	q.push({src, cnt, 0});
	while(!q.empty()){
		PacketInfo p = q.front();
		q.pop();
		if(p.curr==dest) return p.time_elapsed;
		if(p.count_val>1){
			for(int i: g[p.curr]){
				q.push({i, p.count_val-1, p.time_elapsed+1});
			}
		}
	}
	return -1;
}

int bfs_except_incoming(int src, int dest, int cnt){
	queue<PacketParentInfo> q;
	q.push({src, cnt, 0, -1});
	while(!q.empty()){
		PacketParentInfo p = q.front();
		q.pop();
		if(p.curr==dest) return p.time_elapsed;
		if(p.count_val>1){
			for(int i: g[p.curr]){
				if(i!=p.parent) q.push({i, p.count_val-1, p.time_elapsed+1, p.curr});
			}
		}
	}
	return -1;
}



int bfs_k_lines(int src, int dest, int cnt, int k){
	queue<Packet_K_Info> q;
	q.push({src, cnt, 0,k});

	while(!q.empty()){
		Packet_K_Info p = q.front();
		q.pop();
		if(p.curr==dest) return p.time_elapsed;
		if(p.count_val>1){
			for(int i: g[p.curr]){
			      if(k!=0) q.push({i, p.count_val-1, p.time_elapsed+1,k-1});
			}
		}
	}
	return -1;
}



int main(){
	/*
	 * input: number of nodes, edges, topology, source, destination, packet counter
	 */
	cout<<"Enter the number of nodes: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;
	for(int i=0; i<e; i++){
		cout<<"Enter the two vertices of edge "<<i+1<<": ";
		cin>>v1>>v2;
		v1--;
		v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	cout<<"Enter source: ";
	cin>>s;
	cout<<"Enter destination: ";
	cin>>d;
	s--, d--;
	cout<<"Enter the  intial packet hop counter value: ";
	cin>>pkt_cnt;
	cout<<"Enter packet size: ";
	cin>>pkt_sz;

	int time_elapsed;
	double bw;

	// flooding in all lines
	cout<<" Flooding all lines: \n";
	time_elapsed = bfs_all_lines(s, d, pkt_cnt);
	if(time_elapsed!=-1){
		cout<<"One packet sent from source to destination\n";
		cout<<"Time elapsed: "<<time_elapsed<<"\n";
		bw = (double)pkt_sz / (double)time_elapsed;
		cout<<"Bandwidth: "<<bw<<"\n";
	}
	else cout<<"The packet would never reach the destination\n";

//Flooding all line except incoming :
	cout<<" Flooding all line except incoming :\n";
	time_elapsed = bfs_all_lines(s, d, pkt_cnt);
	if(time_elapsed!=-1){
		cout<<"One packet sent from source to destination\n";
		cout<<"Time elapsed: "<<time_elapsed<<"\n";
		bw = (double)pkt_sz / (double)time_elapsed;
		cout<<"Bandwidth: "<<bw<<"\n";
	}
	else cout<<"The packet would never reach the destination\n";

//Flooding choosen K lines:
cout<<" Flooding all choosen K lines:\n";
 cout<<"\nEnter k:";
 cin>>k;

	time_elapsed = bfs_k_lines(s, d, pkt_cnt,k);

	if(time_elapsed!=-1){
		cout<<"\nOne packet sent from source to destination\n";
		cout<<"Time elapsed: "<<time_elapsed<<"\n";
		bw = (double)pkt_sz / (double)time_elapsed;
		cout<<"Bandwidth: "<<bw<<"\n";
	}
	else cout<<"The packet would never reach the destination\n";

cout<<"\nIf k=1:";
time_elapsed = bfs_k_lines(s, d, pkt_cnt,1);
	if(time_elapsed!=-1){
		cout<<"One packet sent from source to destination\n";
		cout<<"Time elapsed: "<<time_elapsed<<"\n";
		bw = (double)pkt_sz / (double)time_elapsed;
		cout<<"Bandwidth: "<<bw<<"\n";
	}
	else cout<<"The packet would never reach the destination\n";



    return 0;
}

