import java.util.Arrays;

public class Solution {
    public static int splitString(String s) {
        int n = s.length();

        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int[] freq = new int[26];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i) - 'a';
            freq[ch]++;

            if (freq[ch] == 1)
                cnt++;

            prefix[i] = cnt;
        }

        Arrays.fill(freq, 0);
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            int idx = s.charAt(i) - 'a';
            freq[idx]++;

            if (freq[idx] == 1)
                cnt++;

            suffix[i] = cnt;
        }

        int splits = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                splits++;
            }
        }
        return splits;
    }
}
