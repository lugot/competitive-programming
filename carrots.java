import java.util.Scanner;

public class carrots
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=in.nextInt();
        int p=in.nextInt();
        in.nextLine();
        
        for (int i=0; i<n; i++) in.nextLine();
        
        System.out.println(p);
    }
}
