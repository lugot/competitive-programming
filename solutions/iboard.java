import java.util.Scanner;

public class iboard
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        while(in.hasNextLine())
        {
            String input=in.nextLine();
            int numOfZeros=0;
            int numOfOnes=0;
            
            for (int i=0; i<input.length(); i++)
            {
                int digit=input.charAt(i);
                int numOfBase2Digits=0;
                while(digit!=0)
                {   if (digit%2==0) numOfZeros++;
                    else numOfOnes++;
                    digit/=2;
                    numOfBase2Digits++;
                }
                numOfZeros+=7-numOfBase2Digits;
            }
            
            if (numOfOnes%2==1 || numOfZeros%2==1)
                System.out.println("trapped");
            else
                System.out.println("free");
        }
        
    }
}
