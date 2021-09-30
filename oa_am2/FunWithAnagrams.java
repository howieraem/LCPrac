public class FunWithAnagrams {

    public static boolean areAnagram(String w1, String w2) {
        char[] chr1 = w1.toCharArray();
        char[] chr2 = w2.toCharArray();

        // Sorting the two arrays and checking for equality also works, but time complexity is higher
        int[] count = new int[26];
        for (char ch : chr1) {
            count[ch - 'a'] = count[ch - 'a'] + 1;
        }

        for (char ch : chr2) {
            count[ch - 'a'] = count[ch - 'a'] - 1;
        }

        for (int n : count) {
            if (n != 0) {
                return false;
            }
        }


        return true;
    }

    public static String key(String word) {
        char[] chrs = word.toCharArray();
        Arrays.sort(chrs);
        return new String(chrs);
    }

    public static List<String> funWithAnagrams(List<String> s) {
        List<String> ans = new LinkedList<>();
        Set<String> found = new HashSet<>();
        for (int i = 0; i < s.size(); ++i) {
            String word = s.get(i);
            String key = key(word);
            if (!found.contains(key)) {
                ans.add(word);
                found.add(key);
            }
        }
        Collections.sort(ans);
        return ans;
    }

    public static void main(String[] args) throws FileNotFoundException {
        // List<String> a = Arrays.asList("code", "doce", "ecod", "framer", "frame");
        List<String> a = Arrays.asList("code", "aaagmnrs", "anagrams", "doce");
        System.out.println(funWithAnagrams(a));
    }

}
