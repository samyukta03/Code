import java.io.*;
public class electricity_shop{
    public int calculateprice(int[] k,int[] d,int b){
        int price=1;
        
        return price;
    }
    public static void main(String[] args){
        Scanner inst = new Scanner(System.in);
        System.out.println("Enter budget");
        int b = inst.nextInt();
        System.out.println("Enter n ");
        int n = inst.nextInt();
        int[] key = new int[n];
        int[] drive = new int[n];
        for(int i=0;i<n;i++){
            System.out.println("Enter keyboard "+i);
            key[i]= inst.nextInt();
            System.out.println("Enter drive "+ i);
            drive[i]= inst.nextInt();           
        }
        int ans = calculateprice(key,drive,b);
        System.out.println(ans);
    }
}