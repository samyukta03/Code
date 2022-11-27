package week9;

import java.util.*;

public class electricity_shop {
        public static int calculateprice(int[] k, int[] d, int b){
            int price=-1;
            int n = k.length;
            ArrayList<Integer>cost = new ArrayList<Integer>(n+n);
            int a = 0;
                for (int i : k)
                    for (int j : d)
                        cost.add(i+j);
//            Collections.sort(cost);
//            for(int i=0;i<cost.size();i++){
//                if(cost.get(i)>b){
//                    continue;
//                }
//                else if(cost.get(i)<=b){
//                    price = Math.max(price,cost.get(i));
//                }
//            }
            Collections.sort(cost,Collections.reverseOrder());
            for(int i=0;i<cost.size();){
                if(cost.get(i)<=b){
                    price = Math.max(price,cost.get(i));
                    break;
                }
                else i++;

            }
            return price;
        }
        public static void main(String[] args) throws Exception{
            Scanner inst = new Scanner(System.in);
//            System.out.println("Enter budget");
//            int b = inst.nextInt();
//            System.out.println("Enter n ");
//            int n = inst.nextInt();
            int b = 60;
//            int[] key = new int[n];
//            int[] drive = new int[n];
            int[]  key = new int[]{40, 50, 60};
            int[] drive = new int[]{5,8,12};
//            for(int i=0;i<n;i++)
//                key[i]= inst.nextInt();
//            for(int i=0;i<n;i++)
//            drive[i]= inst.nextInt();
            int ans = calculateprice(key,drive,b);
            System.out.println(ans);
        }
}
