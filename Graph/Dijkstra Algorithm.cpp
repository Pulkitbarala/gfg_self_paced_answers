class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a priority queue to store (distance, vertex) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Vector to store the shortest distance from the source
        vector<int> dist(V, INT_MAX);

        // Distance from source to source is 0
        dist[S] = 0;

        // Add the source vertex to the priority queue
        pq.push({0, S});

        while (!pq.empty())
        {
            // Extract the vertex with the minimum distance
            int u = pq.top().second;
            int uDist = pq.top().first;
            pq.pop();

            // If the distance is not the latest, skip processing
            if (uDist > dist[u])
                continue;

            // Iterate through adjacent vertices
            for (const auto &edge : adj[u])
            {
                int v = edge[0];
                int weight = edge[1];

                // Check if a shorter path is found
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};