import java.util.Scanner;

public class sumkindofproblem
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int P=Integer.parseInt(in.nextLine());
        
        for (int i=0; i<P; i++)
        {
            int K=in.nextInt();
            int N=in.nextInt();
            in.nextLine();
            
            System.out.println(K+" "+ (N*(N+1)/2) +" "+ (N*N) +" "+ (N*(N+1)) );
        }
    }
}
