#include <bits/stdc++.h>
using namespace std;

typedef vector <int> VI;
typedef vector <VI> VVI;

bool FindMatch(int i, const VVI& w, VI& mr, VI& mc, VI& seen) {
  for (unsigned int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI& w, VI& mr, VI& mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  int ct = 0;
  for (unsigned int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main() {
  int a, b, cases;
  scanf("%d", & cases);
  while (cases--) {
    int s, c, numPersonas;
    scanf("%d", &numPersonas);
    VVI adj(numPersonas, VI(numPersonas));
    VVI graph(numPersonas, VI(numPersonas));
    int numEdges, vert;
    for (int i = 0; i < numPersonas; i++) {
        scanf("%d", &numEdges);
        while (numEdges--) {
            scanf("%d", &vert);
            graph[i].push_back(vert);
        }
    }

    vector <int> V;
    vector <int> V_;
    int result = BipartiteMatching(adj, V, V_);
    printf("%d-%d\n", result, numPersonas - result);
  }
  return 0;
}