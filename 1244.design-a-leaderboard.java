import java.util.*;

// Hash Map + Tree / Sorted Map
// Assuming this will be read-heavy, i.e. top() is called much more than others
// S: O(n)
class Leaderboard {
    Map<Integer, Integer> id2score;
    TreeMap<Integer, Integer> scoreCnts;

    public Leaderboard() {
        id2score = new HashMap<>();  // assume default score for all new/non-existent players is 0
        scoreCnts = new TreeMap<>(Collections.reverseOrder());
    }
    
    // T: O(log(n))
    public void addScore(int playerId, int score) {
        Integer preScore = id2score.getOrDefault(playerId, null);
        if (preScore == null) {
            id2score.put(playerId, score);
            scoreCnts.put(score, scoreCnts.getOrDefault(score, 0) + 1);
        } else {
            int preScoreCnt = scoreCnts.get(preScore);
            if (preScoreCnt > 1) {
                scoreCnts.put(preScore, preScoreCnt - 1);
            } else {
                scoreCnts.remove(preScore);
            }
            score += preScore;
            id2score.put(playerId, score);
            scoreCnts.put(score, scoreCnts.getOrDefault(score, 0) + 1);
        }
    }
    
    // T: O(k)
    public int top(int K) {
        int ans = 0;
        for (Map.Entry<Integer, Integer> e : scoreCnts.entrySet()) {
            int score = e.getKey();
            int cnt = e.getValue();
            int n = Math.min(cnt, K);
            ans += n * score;
            K -= n;
            if (K == 0) {
                break;
            }
        }
        return ans;
    }
    
    // T: O(log(n))
    public void reset(int playerId) {
        Integer preScore = id2score.getOrDefault(playerId, null);
        if (preScore == null) {
            return;
        }

        int preScoreCnt = scoreCnts.get(preScore);
        if (preScoreCnt > 1) {
            scoreCnts.put(preScore, preScoreCnt - 1);
        } else {
            scoreCnts.remove(preScore);
        }
        id2score.remove(playerId);
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */