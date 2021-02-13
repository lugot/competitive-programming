import java.util.Scanner;

public class nastyhacks
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        for (int i=0; i<n; i++)
        {
            int r=in.nextInt();
            int e=in.nextInt();
            int c=in.nextInt();
            in.nextLine();
            
            if (r==e-c) System.out.println("does not matter");
            else if (r>e-c) System.out.println("do not advertise");
            else System.out.println("advertise");
        }
    }
}
