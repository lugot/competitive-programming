import java.util.Scanner;

public class spavanac
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int H=in.nextInt();
        int M=in.nextInt();
        
        M-=45;
        if (M<0)
        {
            M+=60;
            H--;
            if (H<0)
                H+=24;
        }
        
        System.out.println(H+" "+M);
    }
}
