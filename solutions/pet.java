import java.util.Scanner;

public class pet
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
    
        int[] grades=new int[5];
        
        for (int i=0; i<5; i++)
        {
            for (int j=0; j<4; j++)
                grades[i]+=in.nextInt();
            in.nextLine();
        }
        
        int indexMax=0;
        for (int i=0; i<5; i++)
            if (grades[i]>grades[indexMax]) indexMax=i;
        
        System.out.println((indexMax+1)+" "+grades[indexMax]);
    }
    
}
