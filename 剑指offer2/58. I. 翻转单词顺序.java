class Solution {
    /*
    // Solution with built-in string functions 
    public String reverseWords(String s) {
        String[] words = s.trim().split("\\s+");
        int i = 0, j = words.length - 1;
        while (i < j) {
            String tmp = words[i];
            words[i++] = words[j];
            words[j--] = tmp;
        }
        return String.join(" ", words);
    }
    */

    public String reverseWords(String s) {
        char[] a = s.trim().toCharArray();
        int j = a.length - 1, i = j;
        StringBuilder sb = new StringBuilder();
        while (i >= 0) {
            // find the space in front of the word
            while (i >= 0 && a[i] != ' ')  --i;

            // append the word and a delimiter
            for (int k = i + 1; k <= j; ++k) {
                sb.append(a[k]);
            }
            sb.append(' ');

            // find the next word by skipping the spaces
            while (i >= 0 && a[i] == ' ')  --i;
            j = i;
        }
        if (sb.length() > 0) {
            // remove the last space added
            sb.setLength(sb.length() - 1);
        }
        return sb.toString();
    }
}
