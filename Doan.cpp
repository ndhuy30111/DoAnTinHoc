#pragma once
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;
const int MAX = 100;

struct GRAPH {
	int n;
	int data[MAX][MAX];
	int **a=NULL;
	
};
void Khoitao(GRAPH& g)
{
	g.a = (int **)malloc(g.n*sizeof(int *));
	
	for (int i = 0; i < g.n; i++)
	{
		g.a[i] = (int*)malloc(g.n * sizeof(int*));
	}
}
void GanGiatri(GRAPH& g,int start,int end)
{
	cout << g.n << endl;
	cout << start << " " << end<<endl;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			g.a[i][j] = g.data[i][j];
		}
	}
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			cout << g.a[i][j]<<" ";
		}
		cout << endl;
	}
}
void init(GRAPH&);
void Input(GRAPH& g);
void initgraph(const char* File, GRAPH& g, int& start, int& end);
bool empty(GRAPH);
bool full(GRAPH);
void Input(GRAPH&);
void OutPut(GRAPH);
void OutPutGraph(GRAPH g, int dinhdau, int dinhcuoi);
bool dinhnoi(GRAPH, int, int);
void huy(GRAPH);

struct QUEUE
{
	int front, rear;
	int data[MAX];
};
void initQueue(QUEUE&);
bool isemptyQueue(QUEUE);
bool isFull(QUEUE);
void PrintQueue(QUEUE);
void EnQueue(QUEUE& q, int x);
void DeQueue(QUEUE& q, int& temp);
void GetFront(QUEUE q, int& temp);

struct STACK
{
	int sp;
	int data[MAX];
};
void Init_stack(STACK&);
int Empty_stack(STACK);
int Full_stack(STACK);
void Push(STACK&, int x);
void Pop(STACK& s, int& temp);
void top(STACK s, int& temp);

void bfs(GRAPH g, int start, int end);
void dfs(GRAPH g, int start, int end);
void print_father(int start, int end, int father[MAX], const char* File,GRAPH g);
void inputFile(const char* File, GRAPH& g, int start, int end);

bool dinhnoi(GRAPH g, int dinh, int dinhke)
{
	return g.data[dinh][dinhke] != 0 ? true : false;
}
void huy(GRAPH g)
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			g.data[i][j] = 0;
		}
	}
	g.n = 0;
}
void init(GRAPH& g)
{
	g.n = 0;
}
bool empty(GRAPH g)
{
	return g.n == 0 ? true : false;
}
bool full(GRAPH g)
{
	return g.n == MAX ? true : false;
}
void initgraph(const char* File, GRAPH& g, int& start, int& end)
{
	ifstream file;
	file.open(File);
	file >> g.n;
	file >> start >> end;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			file >> g.data[i][j];
		}
	}
	file.close();
}
void Input(GRAPH& g)
{
	cout << "\nNhap So dinh: ";
	cin >> g.n;
	int trongso;
	int d;
	int dn;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			g.data[i][j] = 0;
		}
	}
	while (true)
	{
		cout << "\nNhap dinh va dinh noi: ";
		cin >> d >> dn;;
		cout << "\nNhap trong so: (nhap 0 de ke thuc)";
		cin >> trongso;
		if (trongso == 0)
			break;
		g.data[d][dn] = trongso;
		g.data[dn][d] = trongso;
	}
}
void OutPutGraph(GRAPH g,int dinhdau,int dinhcuoi)
{
	cout << "\n" << g.n;
	cout << "\n" << dinhdau << " " << dinhcuoi;
	cout << endl;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			cout << g.data[i][j] << " ";
		}
		cout << endl;
	}
}
void OutPut(GRAPH g)
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			cout << g.data[i][j] << " ";
		}
		cout << endl;
	}
}

void initQueue(QUEUE& q)
{
	q.front = -1;
	q.rear = -1;
}
bool isemptyQueue(QUEUE q)
{
	return q.front == -1;
}
bool isFull(QUEUE q)
{
	return q.rear - q.front == MAX - 1;
}
void PrintQueue(QUEUE q)
{
	for (int i = q.front; i <= q.rear; i++)
	{
		cout << q.data[i];
	}
}
void EnQueue(QUEUE& q, int x)
{
	if (isFull(q))
		cout << endl << "Queue is Full!!";
	else
	{
		if (q.front == -1)
			q.front = 0;
		else if (q.rear == MAX - 1)
		{
			for (int i = q.front; i <= q.rear; i++)
			{
				q.data[i - q.front] = q.data[i];
				q.rear = MAX - 1 - q.front;
				q.front = 0;
			}
		}
		q.rear++;
		q.data[q.rear] = x;
	}

}
void DeQueue(QUEUE& q, int& temp)
{
	if (!isemptyQueue(q))
	{
		if (q.front == q.rear)
			initQueue(q);
		else
		{
			temp = q.data[q.front];
			q.front = q.front + 1;
		}

	}
}
void GetFront(QUEUE q, int& temp)
{
	temp = q.data[q.rear];
}

void Init_stack(STACK& s)
{
	s.sp = -1;
}
int Empty_stack(STACK s)
{
	return s.sp == -1;
}
int Full_stack(STACK s)
{
	return s.sp == MAX - 1;
}
void Push(STACK& s, int x)
{
	if (Full_stack(s))
		cout << "\nFull";
	else
	{
		s.sp++;
		s.data[s.sp] = x;
	}
}
void Pop(STACK& s, int& temp)
{
	if (Empty_stack(s))
		cout << endl << "Stack empty!!!";
	else
	{
		temp = s.data[s.sp];
		s.data[s.sp--];
	}

}
void top(STACK s, int& temp)
{
	temp = s.data[s.sp];
}

void bfs(GRAPH g, int start, int end)
{
	int temp = start;
	int visit[MAX];
	int father[MAX];
	for (int i = 0; i < g.n; i++)
	{
		visit[i] = 0;
		father[i] = -1;
	}
	QUEUE q;
	initQueue(q);
	EnQueue(q, temp);
	while (!isemptyQueue(q))
	{
		DeQueue(q, temp);
		if (visit[temp] == 0)
		{
			visit[temp] = 1;
			for (int i = g.n - 1; i >= 0; i--)
			{
				if (g.data[temp][i] != 0 && visit[i] == 0)
				{
					EnQueue(q, i);
					father[i] = temp;
				}
			}
		}
	}
	print_father(start, end, father, "bfs.txt",g);
}
void dfs(GRAPH g, int start, int end)
{
	int temp = start;
	int visit[MAX];
	int father[MAX];
	for (int i = 0; i < g.n; i++)
	{
		visit[i] = 0;
		father[i] = -1;
	}
	STACK s;
	Init_stack(s);
	Push(s, temp);
	while (!Empty_stack(s))
	{
		Pop(s, temp);
		if (visit[temp] == 0)
		{
			visit[temp] = 1;

			for (int i = g.n - 1; i >= 0; i--)
			{
				if (g.data[temp][i] != 0 && visit[i] == 0)
				{
					Push(s, i);
					father[i] = temp;
				}
			}
		}
	}
	print_father(start, end, father, "dfs.txt",g);
}

void inputFile(const char* File, GRAPH& g,int start,int end)
{
	ofstream file;
	file.open(File);
	file << g.n << endl;
	file << start<<" " << end<<endl;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			file << g.data[i][j] << " ";
		}
		file << endl;
	}
	file.close();
}

void print_father(int start, int end, int father[MAX], const char* File,GRAPH g)
{
	ofstream f;
	STACK q;
	Init_stack(q);
	f.open(File);
	int tem;
	int temp = end;
	Push(q, end);
	while (1)
	{
		if (start == temp)
		{
			break;
		}
		else if (father[temp] == -1)
			f << "Khong co duong di";
		else {

			temp = father[temp];

			Push(q, temp);
		}
	}
	string a[MAX]{ "Oradea","Zerind" ,"Arack","Fagaras" ,"Timisoara" ,"Flimnicu Vilcea" ,"Lugoj" ,"Pitesti" ,"Mehadia" ,"Dobreata" ,"Craiova" ,"Bucharest" ,"Giu rgiu" ,"Urziceni" ,"Hirsova" ,"Eforie" ,"Vaslui" ,"laSi" ,"Neamt" };

	while (!Empty_stack(q))
	{
		Pop(q, tem);
		if (q.sp == -1)
		{
			for(int i=0;i<g.n;i++)
				if (i == tem)
				{
					f << a[i];
				}
		}
		else
		{
			
			for (int i = 0; i < g.n; i++)
				if (i == tem)
				{
					f << a[i];
					f << "->";
				}
			
		}
	}
	f.close();
}



void main()
{
	GRAPH g;
	int start, end;
	const char* data = "dothi.TXT";
	initgraph("dothi.TXT", g, start, end);
	//inputFile("dothi2.txt", g, start, end);
	//OutPutGraph(g, start, end);
	Khoitao(g);
	GanGiatri(g,start,end);
	bfs(g, start, end);
	dfs(g, start, end);
}
