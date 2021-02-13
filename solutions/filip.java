import java.util.Scanner;

public class filip 
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int A=in.nextInt();
        int B=in.nextInt();
        
        A=(A%10)*100+((A/10)%10)*10+(A/100);
        B=(B%10)*100+((B/10)%10)*10+(B/100);
        
        System.out.println(A>B ? A : B);
    }
    
    public static void print(String s){
        System.out.println(s);
    }
}
