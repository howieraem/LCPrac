#
# @lc app=leetcode id=535 lang=python3
#
# [535] Encode and Decode TinyURL
#
import random

# @lc code=start
class Codec:
    CHARS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" # 62 chars
    DOMAIN = "http://tinyurl.com/"

    LEN = 6  # can represent 62 ^ LEN URLs, as short as possible

    def __init__(self) -> None:
        self.code2url = {}

    # T: O(1)
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        while True:
            code = ''.join(random.choice(Codec.CHARS) for _ in range(Codec.LEN))
            if code not in self.code2url:
                self.code2url[code] = longUrl
                return self.DOMAIN + code

    # T: O(1)
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.code2url[shortUrl[-self.LEN:]]        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end

