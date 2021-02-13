import java.util.Scanner;

public class oddities
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        for (int i=0; i<n; i++)
        {
            int x=Integer.parseInt(in.nextLine());
            if (x%2==0)
                System.out.println(x+" is even");
            else
                System.out.println(x+" is odd");
        }
    }
}
