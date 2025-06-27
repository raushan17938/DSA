class Solution {
    public int compress(char[] chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.length;

        while (i < n) {
            int j = i + 1;
            
            // Count duplicates
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // Store the current character
            chars[ansIndex++] = chars[i];

            int count = j - i;

            // If count > 1, convert to characters and add them
            if (count > 1) {
                String cnt = Integer.toString(count);
                for (char ch : cnt.toCharArray()) {
                    chars[ansIndex++] = ch;
                }
            }

            i = j; // Move to the next group
        }

        return ansIndex;
    }
}
