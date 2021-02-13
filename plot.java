import java.util.Scanner;

public class plot
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int[] poly = new int[n+1];
        for (int i=0; i<n+1; i++) poly[i]=in.nextInt();
        
        int[] C = new int[n+1];
        C[0]=poly[n]; //evaluateFor(poly,0);
        System.out.print(C[0]+" ");
        
        //questo problema si risolve poco con la programmazione,
        // ho trovato una corrispondenza matematica e la uso
        int lastEvaluation=C[0];
        for (int i=1; i<n+1; i++)
        {
            int sumOfCs=0;
            for (int j=0; j<=i-1; j++)
                sumOfCs+=binomialCoefficent(i-1,j)*C[j+1];
            
            int currentEvaluation=evaluateFor(poly,i);
            
            C[i]=currentEvaluation-lastEvaluation-sumOfCs;
            lastEvaluation=currentEvaluation;
            
            System.out.print(C[i]+" ");
        }
        System.out.println();
        
    }
    
    public static int evaluateFor(int[] poly, int x)
    {
        int result=poly[poly.length-1];
        int pow=x;
        
        for (int i=poly.length-2; i>=0; i--)
        {   result+=poly[i]*pow;
            pow*=x;
        }
        
        return result;
    }
    public static int binomialCoefficent(int n, int k)
    {
        return (fact(n)/fact(k)/fact(n-k));
    }
    public static int fact(int n)
    {
        if (n==0 || n==1)
            return 1;
        return n*fact(n-1);
    }
}
