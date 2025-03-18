class Solution {
    // Regex + String
    // T: O(n)
    // S: O(n)
    public String discountPrices(String sentence, int discount) {
        final double F = 1 - discount / 100d;
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            String w = words[i];
            if (w.length() <= 1 || w.charAt(0) != '$') {
                continue;
            }
            w = w.substring(1);
            if (w.chars().allMatch(c -> '0' <= c && c <= '9')) {
                words[i] = String.format("$%.2f", Long.parseLong(w) * F);
            }
        }
        return String.join(" ", words);
    }
}