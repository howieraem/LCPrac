/*
 * @lc app=leetcode id=261 lang=golang
 *
 * [261] Graph Valid Tree
 */
package lc

// @lc code=start
func hasCycle(adj [][]int, u int, p int, vis *[]bool) bool {
	if (*vis)[u] {
		return true
	}
	(*vis)[u] = true
	for _, v := range adj[u] {
		// IMPORTANT: since graph is undirected, we should exclude the case of edge (v, u)
		if v != p && hasCycle(adj, v, u, vis) {
			return true
		}
	}
	return false
}

// A tree is a connected graph without cycles
// DFS solution without union find
// T: O(n)
// S: O(n)
func validTree(n int, edges [][]int) bool {
	adj := make([][]int, n)
	for _, edge := range edges {
		adj[edge[0]] = append(adj[edge[0]], edge[1])
		adj[edge[1]] = append(adj[edge[1]], edge[0])
	}

	vis := make([]bool, n)
	if hasCycle(adj, 0, -1, &vis) { // IMPORTANT: root node does not have a parent, so pass p = -1
		return false
	}

	// If the graph is connected, then all nodes should be visited after DFS hasCycle()
	for _, visited := range vis {
		if !visited {
			return false
		}
	}
	return true
}

// @lc code=end
