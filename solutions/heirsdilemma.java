import java.util.Scanner;

public class heirsdilemma
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int L=in.nextInt();
        int H=in.nextInt();
        
        int countComb=0;
        for (int i=L; i<=H; i++)
        {
            boolean flag=true;
            boolean[] diffDigit = new boolean[9];
            
            int j=i;
            while(j!=0){
                int digit=j%10;
                j/=10;
                
                if (digit==0 || i%digit!=0) flag=false;
                if (digit!=0) diffDigit[digit-1]=true;
            }
            
            int c=0;
            for (j=0; j<9; j++)
                if (diffDigit[j]==true) c++;
            if (c!=6) flag=false;
            
            if (flag==true) countComb++;
        }
        
        System.out.println(countComb);
    }
}
