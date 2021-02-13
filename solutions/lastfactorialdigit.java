import java.util.Scanner;

public class lastfactorialdigit
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int T=Integer.parseInt(in.nextLine());
        
        for (int k=0; k<T; k++)
        {
            int n=Integer.parseInt(in.nextLine());
            int lastDigit=1;
            for (int i=1; i<=n; i++)
                lastDigit=(lastDigit*i)%10;
            
            System.out.println(lastDigit);
        }
    }
}
 
