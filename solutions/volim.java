import java.util.Scanner;

public class volim
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int K=Integer.parseInt(in.nextLine());
        int N=Integer.parseInt(in.nextLine());
        
        int time=0;
        for (int i=0; i<N; i++)
        {
            int T=in.nextInt();
            char Z=in.next().charAt(0);
            in.nextLine();
            
            time+=T;
            if (time>210)
                break;
            
            if (Z=='T') //passo avanti
            {
                if (K==8) K=1;
                else K++;
            }
            //System.out.println(T+" "+Z+" "+K);
        }
        System.out.println(K);
    }
}
