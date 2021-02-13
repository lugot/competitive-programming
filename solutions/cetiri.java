import java.util.Scanner;

public class cetiri
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int[] i=new int[3];
        i[0]=in.nextInt();
        i[1]=in.nextInt();
        i[2]=in.nextInt();
        
        java.util.Arrays.sort(i);
        
        if (i[1]-i[0] > i[2]-i[1])
            System.out.println(i[0]+(i[2]-i[1]));
            
        else if (i[1]-i[0] < i[2]-i[1])
            System.out.println(i[1]+(i[1]-i[0]));
            
        else
            System.out.println(i[2]+(i[2]-i[1]));
    }
}
