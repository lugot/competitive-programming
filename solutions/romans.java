import java.util.Scanner;

public class romans
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        double miles=in.nextDouble();
        
        double paces=miles*1000.0*5280.0/4854.0;
        if (paces-(int)paces > 0.5) paces++;
        
        System.out.println((int)paces);
    }
    
}
