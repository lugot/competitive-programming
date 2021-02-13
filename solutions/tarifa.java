import java.util.Scanner;

public class tarifa
{
    public static void main(String[] args)
    {
        Scanner in= new Scanner(System.in);
        
        int X=in.nextInt();
        int months=in.nextInt();
        
        int used=0;
        for (int i=0; i<months; i++) used+=in.nextInt();
        
        System.out.println(X*(months+1)-used);
    }
}
