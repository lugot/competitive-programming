import java.util.Scanner;

public class primaryarithmetic
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String line=in.nextLine();
        do
        {
            String firstString=line.split(" ")[0];
            String secondString=line.split(" ")[1];
            int maxDigits=java.lang.Math.max( firstString.length() , secondString.length() );
            
            int[] first= new int[maxDigits];
            int[] second= new int[maxDigits];
            
            if (firstString.length()>secondString.length())
            {
                String temp=firstString;
                firstString=secondString;
                secondString=temp;
            }
        
            String zeros="";
            for (int i=0; i<maxDigits-firstString.length(); i++)
                zeros+="0";
            
            firstString=zeros+firstString;
            
            for (int i=firstString.length()-1; i>=0; i--)
                first[i]+=Integer.parseInt(firstString.substring(i,i+1));
            for (int i=secondString.length()-1; i>=0; i--)
                second[i]+=Integer.parseInt(secondString.substring(i,i+1));
        
            int numOfCarry=0;
            int carry=0;
            for (int i=maxDigits-1; i>=0; i--)
            {
                int res=carry+first[i]+second[i];
                if (res>=10)
                {
                    numOfCarry++;
                    carry=1;
                }
                else
                    carry=0;
            }
            
            if (numOfCarry==0)
                System.out.println("No carry operation.");
            else if (numOfCarry==1)
                System.out.println("1 carry operation.");
            else
                System.out.println(numOfCarry+" carry operations.");
            
            line=in.nextLine();
        }while(!line.equals("0 0"));
    }
}
