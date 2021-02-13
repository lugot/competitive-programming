import java.util.Scanner;
import java.text.DecimalFormat;

public class WoodCutting
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int T=in.nextInt();
        
        for (int k=0; k<T; k++)
        {
            int N=in.nextInt();
            
            int[] woods=new int[N];
            int index=0;
            
            for (int i=0; i<N; i++)
            {
                int W=in.nextInt();
                
                int total=0;
                for (int j=0; j<W; j++)
                    total+=in.nextInt();
                
                woods[index++]=total;
            }
            
            java.util.Arrays.sort(woods);
            
            int sum=0;
            long sumIntegral=0;
            for (int i=0; i<N; i++)
            {
                sum+=woods[i];
                sumIntegral+=sum;
            }
            double average=sumIntegral/(double)N;
            
            String pattern=".0000000";
            DecimalFormat decimalFormat = new DecimalFormat(pattern);
            
            System.out.println(decimalFormat.format(average));
        }
    }
}
