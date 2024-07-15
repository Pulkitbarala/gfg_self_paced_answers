int findRoot(int i, int par[], int rank1[]) {
    if (par[i] != i) {
        par[i] = findRoot(par[i], par, rank1);
    }
    return par[i];
}

void union_(int a, int b, int par[], int rank1[]) {
    int rootA = findRoot(a, par, rank1);
    int rootB = findRoot(b, par, rank1);
    if (rootA != rootB) {
        if (rank1[rootA] > rank1[rootB]) {
            par[rootB] = rootA;
        } else if (rank1[rootA] < rank1[rootB]) {
            par[rootA] = rootB;
        } else {
            par[rootB] = rootA;
            rank1[rootA]++;
        }
    }
}

bool isConnected(int a, int b, int par[], int rank1[]) {
    return findRoot(a, par, rank1) == findRoot(b, par, rank1);
}