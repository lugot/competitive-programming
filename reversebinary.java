import java.util.Scanner;

public class reversebinary
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int N=in.nextInt();
        
        int n=N;
        int c=0;
        while(n!=0)
        {
            n/=2;
            c++;
        }
        c--;
        
        int rev=0;
        while (N!=0)
        {
            rev+=pow2(c--)*(N-N/2*2);
            N/=2;
        }
        System.out.println(rev);
    }
    public static int pow2(int e)
    {
        int r=1;
        for (int i=0; i<e; i++) r*=2;
        
        return r;
    }
}
