import java.util.Scanner;

public class natjecanje
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int N=in.nextInt();
        int S=in.nextInt();
        int R=in.nextInt();
        in.nextLine();
        
        int[] kayaks = new int[N];
        for (int i=0; i<S; i++)
            kayaks[in.nextInt()-1]--;
        in.nextLine();
        for (int i=0; i<R; i++)
            kayaks[in.nextInt()-1]++;
            
        //for (int i=0; i<N; i++)
        //    System.out.print(kayaks[i]+" ");
            
        for (int i=0; i<N; i++)
        {
            if (kayaks[i]==1)
            {
                if (i-1>=0 && kayaks[i-1]==-1)
                {
                    kayaks[i-1]++;
                    kayaks[i]--;
                }
                else if (i+1<=N-1 && kayaks[i+1]==-1)
                {
                    kayaks[i+1]++;
                    kayaks[i]--;
                }
            }
        }
        
        int counter=0;
        for (int i=0; i<N; i++)
            if (kayaks[i]==-1) counter++;
        
        System.out.println(counter);
    }
}
