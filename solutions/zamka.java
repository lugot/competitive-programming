import java.util.Scanner;

public class zamka
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int L=Integer.parseInt(in.nextLine());
        int D=Integer.parseInt(in.nextLine());
        int X=Integer.parseInt(in.nextLine());
        
        int N=L;
        while (N!=D)
        {
            int tempN=N, sumDigit=0;
            while (tempN!=0)
            {   sumDigit+=tempN%10;
                tempN/=10;
            }
            if (sumDigit==X) break;
            N++;
        }
        
        int M=D;
        while (M!=L)
        {
            int tempM=M, sumDigit=0;
            while (tempM!=0)
            {   sumDigit+=tempM%10;
                tempM/=10;
            }
            if (sumDigit==X) break;
            M--;
        }
        
        print(N+"\n"+M);
    }
    
    public static void print(String s){
        System.out.println(s);
    }
}
