import java.util.Scanner;

public class faktor
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int A=in.nextInt();
        int I=in.nextInt();
        
        print((A*(I-1)+1)+"");
    }
    
    public static void print(String s){
        System.out.println(s);
    }
}
