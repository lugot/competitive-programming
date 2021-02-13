import java.util.Scanner;

public class akcija
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int N=Integer.parseInt(in.nextLine());
        int numberOfGroups=N/3;
        
        int books[] = new int[100001];
        for (int i=0; i<N; i++)
            books[Integer.parseInt(in.nextLine())]++;
        
        int price=0;
        int groupElem=0;
        for (int i=100000; i>0; i--)
        {   
            if (books[i]>0)
            {
                if (groupElem!=2)
                {
                    //System.out.println("p: "+price+" i: "+i+" "+books[i]);
                    groupElem++;
                    price+=i;
                    books[i]--;
                }
                else //groupElem==2
                {
                    //System.out.println("p: "+price+" i: "+i+" "+books[i]);
                    groupElem=0;
                    books[i]--; //gratis
                }
                if (books[i]!=0) i++;
            }
        }
        
        System.out.println(price);
    }
}
