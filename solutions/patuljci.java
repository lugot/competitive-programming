import java.util.Scanner;

public class patuljci
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int[] dwarves = new int[9];
        for (int i=0; i<9; i++)
            dwarves[i]=Integer.parseInt(in.nextLine());
        
        int i=0,j=0;
        for (i=0; i<9; i++)
        {
            boolean flag=false;
            
            for (j=0; j<9; j++)
            {
                if (j==i) continue;
                
                int c=0;
                for (int u=0; u<9; u++)
                {
                    if (u==i || u==j) continue;
                    c+=dwarves[u];
                }
                if (c==100)
                {
                    flag=true;
                    break;
                }
            }
            if (flag) break;     
        }
        
        for (int k=0; k<9; k++)
        {
            if (k==i || k==j) continue;
            System.out.println(dwarves[k]);
        }
         
    }
}
