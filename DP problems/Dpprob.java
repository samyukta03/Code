 Given a string of numeric values, print all the possible strings that can be formed if each alphabet is mapped from numbers from 1 to 26. Print the answer in lexicographical order.
 Example: Input:  123
Output: “abc aw lc”
class way{
    int val;
    List<String>list;

    way(int val,List<String>list)
    {
        this.val=val;
        this.list=list;
    }
}
class Scratch {
    public static void main(String[] args) {
          List<String>ans=decode("123");
        System.out.println(ans);
    }
    static List<String> decode(String num)
    {
        // List<String>list=new ArrayList<>();
        way[]dp=new way[num.length()+1];
        dp[0]=new way(0,new ArrayList<>());
        if(num.charAt(0)!='0')
        {
            List<String>list=new ArrayList<>();
            list.add(String.valueOf((char)(num.charAt(0)+'0')));
            dp[1]=new way(1,list);
        }
        else{
            dp[1]=new way(1,new ArrayList<>());
        }
        if(num.length()==1 && dp[1].val==1)
        {
            return dp[1].list;
        }
        for(int i=2;i<=num.length();i++)
        {
            int oneDigit=Integer.valueOf(num.substring(i-1,i));
            int twoDigit=Integer.valueOf(num.substring(i-2,i));

            if(oneDigit>=1)
            {
                List<String>list=dp[i-1].list;
               // System.out.println(list+" "+String.valueOf((char)(oneDigit-1+'a')));
                List<String>temp=new ArrayList<>();
                if(list==null || list.size()==0)
                {
                  //  System.out.println("hey");
                    temp.add(String.valueOf((char)(oneDigit-1+'a')));
                }
                for(String s : list)
                {
                    //System.out.println(s+String.valueOf((char)(oneDigit-1+'a')));
                    temp.add(s+String.valueOf((char)(oneDigit-1+'a')));
                }
                if(dp[i]!=null)
                dp[i]=new way(dp[i].val+dp[i-1].val,temp);
                else
                    dp[i]=new way(dp[i-1].val,temp);
            }
            if(twoDigit>=10 && twoDigit<=26)
            {
                List<String>list=dp[i-2].list;
                List<String>temp=new ArrayList<>();
                if(list==null || list.size()==0)
                {
                    temp.add(String.valueOf((char)(twoDigit-1+'a')));
                }
                for(String s : list)
                {
                    temp.add(s+String.valueOf((char)(twoDigit-1+'a')));
                }
                if(dp[i]!=null)
                {
                    List<String>t=dp[i].list;
                    for(String s :temp)
                    {
                        t.add(s);
                    }
                    dp[i]=new way(dp[i].val+dp[i-2].val,t);
                }
                else
                    dp[i]=new way(dp[i-2].val,temp);
            }
        }
        return dp[num.length()].list;
    }
}
