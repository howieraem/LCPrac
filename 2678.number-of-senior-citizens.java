class Solution {
    public int countSeniors(String[] details) {
        final int AGE_IDX1 = 11;
        final int AGE_IDX2 = 12;

        int ans = 0;
        for (String s : details) {
            if (s.length() <= AGE_IDX1) {
                continue;
            }
            char digit1 = s.charAt(AGE_IDX1);
            char digit2 = s.charAt(AGE_IDX2);
            if (('7' <= digit1 && digit1 <= '9') || (digit1 == '6' && '1' <= digit2 && digit2 <= '9')) {
                ++ans;
            }
        }
        return ans;
    }
}