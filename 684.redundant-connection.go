/*
 * @lc app=leetcode id=684 lang=golang
 *
 * [684] Redundant Connection
 */

// @lc code=start
// IMPORTANT: to avoid exploring the same edge from both ends, pass the current parent `p` and
// skip unnecessary recursion calls.
func dfs(u int, v int, p int, adj [][]int) bool {
	if u == v {
		return true
	}
	for _, w := range adj[u] {
		if w != p && dfs(w, v, u, adj) {
			return true
		}
	}
	return false
}

// Plain DFS solution without union find
// T: O(V) same as O(E)
// S: O(V)
func findRedundantConnection(edges [][]int) []int {
	// Theory: a tree with n vertices should have n - 1 edges.
	// According to the problem spec, there is one redundant
	// edge, so there are n edges in total.
	adj := make([][]int, len(edges))

	var res []int
	for _, edge := range edges {
		// Convert to 0-indexed
		u := edge[0] - 1
		v := edge[1] - 1

		if dfs(u, v, -1, adj) { // The first node in DFS doesn't have a parent, so pass -1
			res = edge
			break
		}

		// Undirected graph
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}
	return res
}

// @lc code=end

