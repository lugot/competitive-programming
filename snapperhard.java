import java.util.Scanner;

public class snapperhard
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int T=Integer.parseInt(in.nextLine());
        for (int z=0; z<T; z++)
        {
            String s=in.nextLine();
            int N=Integer.parseInt(s.split(" ")[0]);
            int K=Integer.parseInt(s.split(" ")[1]);
            
            int[] snapperStatus=new int[N+1];
            int index=0;
            while (K!=0 && index<N+1)
            {   
                snapperStatus[index++]=K%2;
                K/=2;
            }
            
            int[] snapperPowered=new int[N+1];
            snapperPowered[0]=1;
            for (int i=1; i<N+1; i++)
                if (snapperPowered[i-1]==1 && snapperStatus[i-1]==1)
                    snapperPowered[i]=1;
                    
            String toPrint=(snapperPowered[N]==1 ? "ON" : "OFF");
                    
            System.out.println("Case #"+(z+1)+": "+toPrint);
                
        }
    }
}
