import java.util.Scanner;

public class ladder
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int h=in.nextInt();
        int v=in.nextInt();
        
        double L= h / Math.sin(Math.toRadians(v)) +1;
        
        System.out.println((int) L);
    }
}
Q
