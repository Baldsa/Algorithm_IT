#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
// vec[0] = [(1,7) , (2,6), ]
// vec[1] = [(0,7), (4,8)]
int main() {
    setlocale(LC_ALL, "ru");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n); // Создали вектор, в котором каждый элемент вектор, состоящий из пары int int. Что-то типа двумерного массива. 
    for (int i = 0; i < m; i++) {
        int u, v, w; // Два ребра и вес между ними
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));// Создали пару ребро u свзяано с ребром v весом w дальше тоже самое  только на оборот, работает для неориентированного графа.
        graph[v].push_back(make_pair(u, w));
    }
    int start_node;
    cout << "Введите вершину, с которой нужно искать минимальный путь "; cin >> start_node;
    vector<int> dist(n, INF); // Инициализируем вектор dist размером n, значением INF
    dist[start_node] = 0; // рассотяние до старта равно 0 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Создали очередь каждый элемент этой очереди будет содержать пару int int, базой для очереди(откуда брать потом значения) является вектор и последний аргумент этой очереди отвечает за то как будут расположены элементы очереди в ней. В данном случае буду разположены по неубыванию, то есть меньшие элементы имеют больший приоритет. 
    pq.push(make_pair(0, start_node));
    while (!pq.empty()) {
        int min_node = pq.top().second;
        int min_len = pq.top().first;// берем значение номер вершины из минимальной элемента очереди, так как очередь отсортирована, .second отвечает за то какой элемент пары мы берем.
        pq.pop();
        if (min_len > dist[min_node]) continue;
        for (auto v : graph[min_node]) { // обход всех соседей вершины 'u'
            int new_dist = dist[min_node] + v.second;
            if ((new_dist < dist[v.first]) && new_dist >= 0) {
                dist[v.first] = new_dist;
                pq.push(make_pair(new_dist, v.first));
            }
        }

    }
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INF) cout << "INF ";
        else cout << "До " << i << " вершины расстояние равно " << dist[i] << '\n';
    }
    cout << endl;
    return 0;
}
