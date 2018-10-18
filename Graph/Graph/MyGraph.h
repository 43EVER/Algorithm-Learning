#pragma once
#include <stdlib.h>
#include <iostream>
#include <queue>

class Graph {
private:
	int **map;
	int m;
	int INF = 0x3f3f3f3f;
	bool *visited;
	bool hasDirection;

	void _dfs(int u) {
		visited[u] = true;
		for (int i = 0; i < m; i++) {
			if (map[u][i] != -INF && visited[i] == false) {
				std::cout << "from " << u << " to " << i << " is " << map[u][i] << std::endl;
				_dfs(i);
			}
		}
	}

public:
	Graph(int m, bool hasDireciton = false) : m(m), hasDirection(hasDireciton) {
		map = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++) {
			map[i] = (int*)malloc(sizeof(int) * m);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				map[i][j] = -INF;
		}
	}

	void addEdge(int u, int v, int w) {
		map[u][v] = w;
		if (hasDirection == false)
			map[v][u] = w;
	}

	void dfs(int u) {
		visited = (bool*)malloc(sizeof(bool) * m);
		memset(visited, false, sizeof(bool) * m);
		_dfs(u);
		free(visited);
	}

	void bfs(int u) {
		std::queue<int> q;
		visited = (bool*)malloc(sizeof(bool) * m);
		memset(visited, false, sizeof(bool) * m);
		q.push(u);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			visited[cur] = true;
			for (int i = 0; i < m; i++) {
				if (map[cur][i] != -INF && visited[i] == false) {
					std::cout << "from " << cur << " to " << i << " is " << map[cur][i] << std::endl;
					q.push(i);
				}
			}
		}
		free(visited);
	}

	~Graph() {
		for (int i = 0; i < m; i++)
			free(map[i]);
		free(map);
	}
};

struct GraphNode {
	int u, v, w;
	int last;
	GraphNode(int u, int v, int w, int last = -1) : u(u), v(v), w(w), last(last) {}
};

class Graph2 {
private:
	int INF = 0x3f3f3f3f;
	GraphNode *edges;
	int *vertexes;
	int cnt = 0;
	int nvertexes;
	int nedges;
	bool hasDirection;
	bool *visited;

	void _addEdge(int u, int v, int w) {
		edges[cnt].last = vertexes[u];
		vertexes[u] = cnt;
		edges[cnt].u = u;
		edges[cnt].v = v;
		edges[cnt].w = w;
		cnt++;
	}

	void _dfs(int u) {
		visited[u] = true;
		int tmp = vertexes[u];
		while (tmp != -1) {
			if (visited[edges[tmp].v] == false) {
				std::cout << "from " << edges[tmp].u << " to " << edges[tmp].v << " is " << edges[tmp].w << std::endl;
				_dfs(edges[tmp].v);
			}
			tmp = edges[tmp].last;
		}
	}

public:
	Graph2(int vertexes, int edges, bool hasDirection = false) : nvertexes(vertexes), nedges(edges), hasDirection(hasDirection) {
		this->vertexes = (int*)malloc(sizeof(int) * nvertexes);
		this->edges = (GraphNode*)malloc(sizeof(GraphNode) * nedges);
		for (int i = 0; i < nvertexes; i++)
			this->vertexes[i] = -1;
	}

	void addEdge(int u, int v, int w) {
		_addEdge(u, v, w);
		if (hasDirection == false)
			_addEdge(v, u, w);
	}

	void dfs(int u) {
		visited = (bool*)malloc(sizeof(bool) * nvertexes);
		memset(visited, false, sizeof(bool) * nvertexes);
		_dfs(u);
		free(visited);
	}

	void bfs(int u) {
		std::queue<int> q;
		visited = (bool*)malloc(sizeof(bool) * nvertexes);
		memset(visited, false, sizeof(bool) * nvertexes);
		q.push(u);
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			visited[curr] = true;
			int tmp = vertexes[curr];
			while (tmp != -1) {
				if (visited[edges[tmp].v] == false) {
					std::cout << "from " << edges[tmp].u << " to " << edges[tmp].v << " is " << edges[tmp].w << std::endl;
					q.push(edges[tmp].v);
				}
				tmp = edges[tmp].last;
			}
		}
		free(visited);
	}
};