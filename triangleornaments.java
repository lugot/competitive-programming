import java.lang.Math;
import java.util.Scanner;

public class TriangleOrnaments
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        
        double rod=0;
        for (int i=0; i<n; i++)
        {
            double A=in.nextDouble();
            double B=in.nextDouble();
            double C=in.nextDouble();
            in.nextLine();
            
            double beta=Math.acos((B*B-A*A-C*C)/(-2*A*C));
            
            double mC=0.5*Math.sqrt(2*(B*B+A*A)-C*C);
            double area=0.5*(C/2)*A*Math.sin(beta);
            
            double psi=Math.asin((4*area)/(C*mC));
            
            rod+=C*Math.cos(psi-Math.PI/2);
            System.out.println(C*Math.cos(psi-Math.PI/2)+" psi: "+psi);
        }
        System.out.println(rod);
    }
}
