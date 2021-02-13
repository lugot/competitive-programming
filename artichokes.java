import java.util.Scanner;
import java.text.DecimalFormat;

public class artichokes
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int p=in.nextInt();
        int a=in.nextInt();
        int b=in.nextInt();
        int c=in.nextInt();
        int d=in.nextInt();
        int n=in.nextInt();
        
        double max=p*( Math.sin(a*1+b) + Math.cos(c*1+d) + 2);
        double largestDecline=0.0;
        
        for (int x=2; x<=n; x++)
        {
            double price=p*( Math.sin(a*x+b) + Math.cos(c*x+d) + 2);

            if (price>max)
                max=price;
            else if (max-price>largestDecline)
                largestDecline=max-price;
        }
        System.out.println(largestDecline);
    }
}

