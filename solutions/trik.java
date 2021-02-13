import java.util.Scanner;

public class trik
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String moves=in.nextLine();
        int left=1;
        int middle=0;
        int right=0;
        
        for (int i=0; i<moves.length(); i++)
        {
            if (moves.charAt(i)=='A')
            {   
                int temp=left;
                left=middle;
                middle=temp;
            }
            if (moves.charAt(i)=='B')
            {   
                int temp=middle;
                middle=right;
                right=temp;
            }
            if (moves.charAt(i)=='C')
            {   
                int temp=left;
                left=right;
                right=temp;
            }
            //if (left==1) System.out.println(1);
            //if (middle==1) System.out.println(2);
            //if (right==1) System.out.println(3);
            
        }
        
        if (left==1) System.out.println(1);
        if (middle==1) System.out.println(2);
        if (right==1) System.out.println(3);
    }
}
