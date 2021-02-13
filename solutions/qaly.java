import java.util.Scanner;

public class qaly
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        
        double qaly=0;
        for (int i=0; i<n; i++)
        {
            double quality=in.nextDouble();
            double period=in.nextDouble();
            qaly+= quality*period;
            
            System.out.println(quality+" "+period);
            
            in.nextLine();
        }
        System.out.println(qaly);
    }
}
