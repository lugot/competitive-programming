import java.util.Scanner;
import java.util.*;

public class a1paper
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        in.nextLine();
       	
        int[] sheets = new int[n];
        
        sheets[0]=1;
        int k=1;
        for (; k<n; k++)
        {
            sheets[k]=(sheets[k-1])*2 - in.nextInt();
            if (sheets[k]<=0)
            {   sheets[k]=0;
                break;
            }
        }
        if (k==n && sheets[n-1]>0)
            System.out.println("impossible");
        else
        {
            
            double[] tape = new double[n];
            tape[0]=Math.pow(2,-3.0/4);
            tape[1]=Math.pow(2,-5.0/4);
            
            for (int i=2; i<n; i++)
                tape[i]=tape[i-2]/2;
            
            double tapeLenght=0;
            for (int i=0; i<n && sheets[i]!=0; i++)
                tapeLenght+=sheets[i]*tape[i];
            
            System.out.println(tapeLenght);
        }
    }
}
