import java.util.Scanner;

public class irepeatmyself
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        
        for (int z=0; z<n; z++)
        {
            String s=in.nextLine();
            boolean flag=false;
            
            for (int length=1; length< s.length()+1; length++)
            {
                String p=s.substring(0,0+length);
                int lengthRate=s.length() / length;
                
                String pxn=p;
                for (int i=0; i<lengthRate+1; i++)
                    pxn+=p;
                
                if (pxn.substring(0,s.length()).equals(s))
                {
                    System.out.println(length);
                    flag=true;
                    break;
                }
            }
        }
    }
}
