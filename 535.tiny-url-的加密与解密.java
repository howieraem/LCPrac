import java.util.Map;
import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=535 lang=java
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
public class Codec {
    private Map<String, String> m = new HashMap<>();
    private static final String PREFIX = "http://tinyurl.com/";
    private static final String CHS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        char[] suffix = new char[6];
        while (true) {
            for (int i = 0; i < 6; ++i) {
                // randomly picks a character from the set of 62 characters 
                suffix[i] = CHS.charAt((int) Math.random() * 62);
            }
            String shortUrl = PREFIX + String.valueOf(suffix);
            if (!m.containsKey(shortUrl)) {
                m.put(shortUrl, longUrl);
                return shortUrl;
            }
        }
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return m.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
// @lc code=end

