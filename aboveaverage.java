import java.util.Scanner;
import java.text.DecimalFormat;

public class aboveaverage
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int C=Integer.parseInt(in.nextLine());
        
        for (int k=0; k<C; k++)
        {
            int N=in.nextInt();
            int[] grades = new int[N];
            int avg=0;
            
            for (int j=0; j<N; j++)
            {   
                if (!in.hasNextInt()) in.nextLine();
                grades[j]=in.nextInt();
                avg+=grades[j];
            }
            avg/=N;
            
            int aboveAvg=0;
            for (int i=0; i<N; i++)
                if (grades[i]>avg) aboveAvg++;
        
            aboveAvg=1;
        
            String pattern= "00.000";
            DecimalFormat decimalFormat = new DecimalFormat(pattern);
            String aboveAvgPerc= decimalFormat.format((double)aboveAvg/N*100);
            
            System.out.println(aboveAvgPerc+"%");
        }
    
    }
}
