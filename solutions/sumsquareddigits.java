import java.util.Scanner;

public class sumsquareddigits
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int P=Integer.parseInt(in.nextLine());
        
        for (int j=0; j<P; j++)
        {
            int K=in.nextInt();
            int b=in.nextInt();
            int n=in.nextInt();
            in.nextLine();
            
            int SSD=0;
            while (n!=0)
            {
                SSD+=(n%b)*(n%b);
                n/=b;
            }
            
            print(K+" "+SSD);
        }
    }
    
    public static void print(String s){
        System.out.println(s);
    }
}
