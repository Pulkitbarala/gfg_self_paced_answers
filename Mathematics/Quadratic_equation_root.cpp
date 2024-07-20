class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        vector<int> roots;
        double det = (b * b) - (4.0 * a * c);
        if (det < 0) { // check if no roots exist
            roots.push_back(-1);
            return roots;
        }
        det = sqrt(det);
        double detPlus = floor((-b + det) / (2.0 * a));
        double detMinus = floor((-b - det) / (2.0 * a));
        if (detPlus < detMinus) {
            roots.push_back((int)detMinus);
            roots.push_back((int)detPlus);
        } else {
            roots.push_back((int)detPlus);
            roots.push_back((int)detMinus);
        }
        return roots;
    }
};
