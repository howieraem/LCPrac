class Solution {
    // two pointers + stack
    // T: O(n)
    // S: O(n) java immutable string
    public String clearDigits(String s) {
        int j = 0;
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < sb.length(); ++i) {
            char c = sb.charAt(i);
            if ('0' <= c && c <= '9') {
                --j;
            } else {
                sb.setCharAt(j++, c);
            }
        }
        return sb.substring(0, j).toString();
    }
}