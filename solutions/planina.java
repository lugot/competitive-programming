import java.util.Scanner;

public class planina
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int N=in.nextInt();
        
        int sidePoints=2;
        for (int i=0; i<N; i++)
            sidePoints=2*sidePoints-1;
        
        System.out.println(sidePoints*sidePoints);
    }
    
}
