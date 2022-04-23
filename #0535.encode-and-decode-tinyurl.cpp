class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                     "GHIJKLMNOPQRSTUVWXYZ0123456789";
        string shorturl;
        int size;
        if (longUrl2id.find(longUrl) == longUrl2id.end()) {
            size = longUrl2id.size();
            longUrl2id.insert(pair<string, int>(longUrl, size));
            id2longUrl.insert(pair<int, string>(size, longUrl));
        } else {
            size = longUrl2id[longUrl];
        }

        while (size) {
            shorturl.push_back(map[size % 62]);
            size = size / 62;
        }
        reverse(shorturl.begin(), shorturl.end());
        return shorturl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        int length = shortUrl.length();
        int id = 0;
        for (int i=0; i < length; i++) {
            if ('a' <= shortUrl[i] && shortUrl[i] <= 'z')
              id = id * 62 + shortUrl[i] - 'a';
            if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z')
              id = id * 62 + shortUrl[i] - 'A' + 26;
            if ('0' <= shortUrl[i] && shortUrl[i] <= '9')
              id = id * 62 + shortUrl[i] - '0' + 52;
        }
        return id2longUrl[id];
    }

private:
    map<string, int> longUrl2id;
    map<int, string> id2longUrl;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
