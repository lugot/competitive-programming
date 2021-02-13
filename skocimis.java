import java.util.Scanner;

public class skocimis
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int A=in.nextInt();
        int B=in.nextInt();
        int C=in.nextInt();
        
        int moves=0;
        while(B-A-1>=1 || C-B-1>=1)
        {   
            if (B-A-1 >= C-B-1)
            {
                C=B; B=A+1;
                moves++;
            }
            else
            {
                A=B; B++;
                moves++;
            }
        }
        System.out.println(moves);
    }
}
