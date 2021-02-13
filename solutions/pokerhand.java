import java.util.Scanner;

public class pokerhand
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int[] k=new int[13];
        for (int i=0; i<5; i++)
        {
            String card=in.next().charAt(0)+"";
            
            int value=0;
            if (card.equals("A"))
                value=0;
            else if (card.equals("T"))
                value=9;
            else if (card.equals("J"))
               value=10;
            else if (card.equals("Q"))
                value=11;
            else if (card.equals("K"))
                value=12;
            else
                value=Integer.parseInt(card)-1;
            
            k[value]++;
        }
        
        int max=0;
        for (int i=0; i<13; i++)
            if (k[i]>max) max=k[i];
        
        System.out.println(max);
    
    }
}
