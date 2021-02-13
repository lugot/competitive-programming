import java.util.Scanner;

public class different
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        while(in.hasNext())
        {
            long n1=in.nextLong();
            long n2=in.nextLong();
            long diff=n1-n2;
            
            System.out.println(diff<0 ? diff*-1 : diff);
            
        }
    }
}
