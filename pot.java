import java.util.Scanner;

public class pot
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int N=Integer.parseInt(in.nextLine());
        
        int X=0;
        for (int i=0; i<N; i++)
        {
            int P=Integer.parseInt(in.nextLine());
            X+=pow(P/10,P%10);
        }
        
        System.out.println(X);
        
    }
    public static int pow(int b, int e)
    {
        int r=1;
        for (int i=0; i<e; i++) r*=b;
        
        return r;
    }
}
