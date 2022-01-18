import java.util.*;
/*
 * @lc app=leetcode.cn id=399 lang=java
 *
 * [399] 除法求值
 */

// @lc code=start
class Pair<K, V> {
    K k;
    V v;

    public Pair(K _k, V _v) {
        k = _k;
        v = _v;
    }
}

class UF {
    private Map<String, Pair<String, Double>> parents;

    public UF() {
        parents = new HashMap<>();
    }

    public void union(String a, String b, double v) {
        // a / b = v, make the denominator as parent and numerator as child.
        boolean hasA = parents.containsKey(a), hasB = parents.containsKey(b);
        if (!hasA && !hasB) {
            // Neither a nor b in UF, base case is b / b = 1
            parents.put(a, new Pair<>(b, v));
            parents.put(b, new Pair<>(b, 1.));
        } else if (!hasA) {
            parents.put(a, new Pair<>(b, v));
        } else if (!hasB) {
            // If numerator in UF but not denominator, need to store the reciprocal
            parents.put(b, new Pair<>(a, 1. / v));
        } else {
            // a / b = v1, b / c = v2 => a / c = v1 * v2
            Pair<String, Double> rootA = find(a), rootB = find(b);
            parents.put(rootA.k, new Pair<>(rootB.k, v / rootA.v * rootB.v));
        }
    }

    public Pair<String, Double> find(String x) {
        Pair<String, Double> p = parents.getOrDefault(x, null);
        if (p == null)  return null;
        if (x != p.k) {
            Pair<String, Double> np = find(p.k);
            p.k = np.k;
            p.v *= np.v;
        }
        return p;
    }
}

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        UF uf = new UF();

        for (int i = 0; i < equations.size(); ++i) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            double v = values[i];
            uf.union(a, b, v);
        }

        int nq = queries.size();
        double[] res = new double[nq];
        for (int i = 0; i < nq; ++i) {
            String a = queries.get(i).get(0), b = queries.get(i).get(1);
            Pair<String, Double> pa = uf.find(a), pb = uf.find(b);
            if (pa == null || pb == null || pa.k != pb.k) {
                // Either one of the query symbols does not exist in equations, 
                // or the symbols are not correlated 
                res[i] = -1.;
            } else {
                res[i] = pa.v / pb.v;
            }
        }
        return res;
    }
}
// @lc code=end

