import java.util.Scanner;
import java.util.Random;

public class bookingaroom
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int r=in.nextInt();
        int n=in.nextInt();
        
        in.nextLine();
        boolean[] booked=new boolean[r+1];
        for (int i=0; i<n; i++)
            booked[Integer.parseInt(in.nextLine())]=true;
        
        if (n==r)
            System.out.println("too late");
        else
        {
            Random rand = new Random();
            int a;
            do
            {
                a=rand.nextInt(r) + 1;
            }while(booked[a]==true);
            System.out.println(a);
        }
    }
}
