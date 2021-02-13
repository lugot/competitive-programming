import java.util.Scanner;

public class sibice
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int N=in.nextInt();
        int W=in.nextInt();
        int H=in.nextInt();
        in.nextLine();
        
        double diag=Math.sqrt(W*W+H*H);
        for (int i=0; i<N; i++)
        {
            int L=Integer.parseInt(in.nextLine());
            if (L<=diag) System.out.println("DA");
            else System.out.println("NE");
        }
    }
}
