class Solution {
    public:
const long long mod = 1000000007;
long long graph[1001][1001];

long long minDistance(vector<long long>& dist, vector<bool>& sptSet, long long V) {
    long long min = INT_MAX;
    long long min_index = -1;

    for (long long v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

vector<long long> dijkstra(long long src, long long V) {
    vector<long long> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0LL;

    for (long long count = 0; count < V - 1; count++) {
        long long u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (long long v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

long long solve(long long V, long long E, vector<vector<long long>>& edges, long long S, long long K, vector<long long>& flagged) {
    for (auto& row : edges) {
        long long u = row[0] - 1;
        long long v = row[1] - 1;
        long long w = row[2];
        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<long long> all_dist = dijkstra(S - 1, V);
    vector<long long> distances;

    for (long long a : flagged) {
        distances.push_back(all_dist[a - 1]);
    }

    long long ans = 0;
    sort(distances.begin(), distances.end());

    for (int i = 0; i < K - 1; i++) {
        ans += 2 * distances[i];
    }

    ans += distances[K - 1];
    return ans;
}
};