import java.util.Scanner;

public class aliennumbers
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int T=Integer.parseInt(in.nextLine());
        
        for (int k=0; k<T; k++)
        {
            String alienNumber=in.next();
            String sourceLanguage=in.next();
            String targetLanguage=in.next();
            
            //to decimal 
            int decimal=0;
            for (int i=alienNumber.length()-1; i>=0; i--)
            {
                int j=0;
                for (; j<sourceLanguage.length(); j++)
                    if (sourceLanguage.charAt(j)==alienNumber.charAt(i)) break;
                    
                decimal+=j*pow(sourceLanguage.length(),alienNumber.length()-i-1); /////////////// casino esponenziales
                
                //System.out.println(decimal+" "+alienNumber.charAt(i)+"j:"+j+"o"+(sourceLanguage.length()-i-1));
            }
            
            String s="";
            while (decimal!=0)
            {
                s= targetLanguage.charAt(decimal%targetLanguage.length()) +s;
                decimal/=targetLanguage.length();
            }
            System.out.println("Case #"+(k+1)+": "+s);
        }
    }
    
    public static int pow(int b, int e)
    {
        int r=1;
        for (int i=0; i<e; i++) r*=b;
        
        return r;
    }
}
