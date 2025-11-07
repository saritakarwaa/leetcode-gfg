class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>m=new HashMap<>();
        int i=0,j=0;
        int maxi=0;
        while(j<s.length()){
            char c=s.charAt(j);
            m.put(c,m.getOrDefault(c,0)+1);
            if(m.size()==j-i+1) maxi=Math.max(maxi,j-i+1);
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    char leftChar = s.charAt(i);
                    m.put(leftChar, m.get(leftChar) - 1);
                    if (m.get(leftChar) == 0) {
                        m.remove(leftChar);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
}